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
	void openCamara();      // ������ͷ
	void readFarme();       // ��ȡ��ǰ֡��Ϣ
	void closeCamara();     // �ر�����ͷ��
	void takingPictures();  // ����

private:
	Ui::Widget *ui;

	QTimer    *timer;
	QImage    *imag;
	CvCapture *cam;// ��Ƶ��ȡ�ṹ�� ������Ϊ��Ƶ��ȡ������һ������
	IplImage  *frame;//����IplImage����ָ�룬���������ڴ�ռ������ÿһ֡ͼ��
};

Widget::Widget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::CameraTestClass)
{
	ui->setupUi(this);

	cam = NULL;
	timer = new QTimer(this);
	imag = new QImage();         

	//�ź�
	connect(timer, &QTimer::timeout, this, &Widget::readFarme);// ʱ�䵽����ȡ��ǰ����ͷ��Ϣ
	connect(ui->pushButton_open, &QPushButton::clicked, this, &Widget::openCamara); //������ͷ
	connect(ui->pushButton_photo, &QPushButton::clicked, this, &Widget::takingPictures);//����
	connect(ui->pushButton_close, &QPushButton::clicked, this, &Widget::closeCamara);    //�ر�����ͷ



}

Widget::~Widget()
{
	closeCamara();
	delete ui;
}


void Widget::openCamara()
{
	cam = cvCreateCameraCapture(0);//������ͷ��������ͷ�л�ȡ��Ƶ
	timer->start(10);        

	cout << "������ͷ";
}

void Widget::readFarme()
{
	frame = cvQueryFrame(cam);  // ������ͷ��ץȡ������ÿһ֡
	// ��ץȡ����֡��ת��ΪQImage��ʽ��
	QImage image = QImage((const uchar *)frame->imageData,
		camerawidth,
		cameraheight,
		QImage::Format_RGB888).rgbSwapped();
	//ʹ�� mirrored �� ˮƽ�����ͼƬ �ٴξ����������ʾ����ȷ��
	ui->label_camera->setPixmap(QPixmap::fromImage(image.mirrored(true, false)));
	cout << "��ȡ����ͷ��Ϣ";
}


/*************************
********* ���� ***********
**************************/
void Widget::takingPictures()
{
	frame = cvQueryFrame(cam);  // ������ͷ��ץȡ������ÿһ֡
	// ��ץȡ����֡��ת��ΪQImage��ʽ��QImage::Format_RGB888��ͬ������ͷ�ò�ͬ�ĸ�ʽ��
	QImage image = QImage((const uchar *)frame->imageData,
		camerawidth,
		cameraheight,
		QImage::Format_RGB888).rgbSwapped();
	ui->label_image->setPixmap(QPixmap::fromImage(image.mirrored(true, false)));
	cout << "����";
}

void Widget::closeCamara()
{
	timer->stop();          // ֹͣ��ȡ���ݡ�
	cvReleaseCapture(&cam);//�ͷ��ڴ棻
	cout << "�ر�����ͷ���ͷ���Դ��";
}
