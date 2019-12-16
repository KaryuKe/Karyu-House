#include "ui_CameraTest.h"
#include <QDebug>
#include <QtWidgets/QWidget>
#define cout qDebug() << "[ "<<__FILE__<<" : "<<__LINE__<<" ]"
#define camerawidth 1280
#define cameraheight 720
#include <QWidget>
#include <QImage>
#include <QTimer>   
#include <highgui.h>  
#include <cv.h>
namespace Ui {
	class Widget;
}

class Widget : public QWidget
{
	Q_OBJECT

public:
	explicit Widget(QWidget *parent = 0);
	~Widget();

private slots:
	void openCamara();      // 打开摄像头
	void readFarme();       // 读取当前帧信息
	void closeCamara();     // 关闭摄像头。
	void takingPictures();  // 拍照

private:
	Ui::Widget *ui;

	QTimer    *timer;
	QImage    *imag;
	CvCapture *cam;// 视频获取结构， 用来作为视频获取函数的一个参数
	IplImage  *frame;//申请IplImage类型指针，就是申请内存空间来存放每一帧图像
};

Widget::Widget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::CameraTestClass)
{
	ui->setupUi(this);

	cam = NULL;
	timer = new QTimer(this);
	imag = new QImage();         

	//信号
	connect(timer, &QTimer::timeout, this, &Widget::readFarme);// 时间到，读取当前摄像头信息
	connect(ui->pushButton_open, &QPushButton::clicked, this, &Widget::openCamara); //打开摄像头
	connect(ui->pushButton_photo, &QPushButton::clicked, this, &Widget::takingPictures);//照相
	connect(ui->pushButton_close, &QPushButton::clicked, this, &Widget::closeCamara);    //关闭摄像头



}

Widget::~Widget()
{
	closeCamara();
	delete ui;
}


void Widget::openCamara()
{
	cam = cvCreateCameraCapture(0);//打开摄像头，从摄像头中获取视频
	timer->start(10);        

	cout << "打开摄像头";
}

void Widget::readFarme()
{
	frame = cvQueryFrame(cam);  // 从摄像头中抓取并返回每一帧
	// 将抓取到的帧，转换为QImage格式。
	QImage image = QImage((const uchar *)frame->imageData,
		camerawidth,
		cameraheight,
		QImage::Format_RGB888).rgbSwapped();
	//使用 mirrored 将 水平方向的图片 再次镜像回来，显示就正确了
	ui->label_camera->setPixmap(QPixmap::fromImage(image.mirrored(true, false)));
	cout << "读取摄像头信息";
}


/*************************
********* 拍照 ***********
**************************/
void Widget::takingPictures()
{
	frame = cvQueryFrame(cam);  // 从摄像头中抓取并返回每一帧
	// 将抓取到的帧，转换为QImage格式。QImage::Format_RGB888不同的摄像头用不同的格式。
	QImage image = QImage((const uchar *)frame->imageData,
		camerawidth,
		cameraheight,
		QImage::Format_RGB888).rgbSwapped();
	ui->label_image->setPixmap(QPixmap::fromImage(image.mirrored(true, false)));
	cout << "拍照";
}

void Widget::closeCamara()
{
	timer->stop();          // 停止读取数据。
	cvReleaseCapture(&cam);//释放内存；
	cout << "关闭摄像头，释放资源。";
}
