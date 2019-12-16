#include "Capture.h" 
#include "ui_QtGuiApplication1.h" 

Capture::Capture(QWidget *parent) :
	QWidget(parent),
	ui(Ui::Capture())
{
	ui->setupUi(this);

	cam = NULL;
	timer = new QTimer(this);
	imag = new QImage();         // ��ʼ�� 

	/*�źźͲ�*/
	connect(timer, SIGNAL(timeout()), this, SLOT(readFrame()));  // ʱ�䵽����ȡ��ǰ����ͷ��Ϣ 
	connect(ui->open, SIGNAL(clicked()), this, SLOT(openCamera()));
	connect(ui->pic, SIGNAL(clicked()), this, SLOT(takingPictures()));
	connect(ui->closeCam, SIGNAL(clicked()), this, SLOT(closeCamera()));
}

/******************************
********* ������ͷ ***********
*******************************/
void Capture::openCamera()
{
	cam = cvCreateCameraCapture(0);//������ͷ��������ͷ�л�ȡ��Ƶ 

	timer->start(33);              // ��ʼ��ʱ����ʱ�򷢳�timeout()�ź� 
}

/*********************************
********* ��ȡ����ͷ��Ϣ ***********
**********************************/
void Capture::readFrame()
{
	frame = cvQueryFrame(cam);// ������ͷ��ץȡ������ÿһ֡ 
	// ��ץȡ����֡��ת��ΪQImage��ʽ��QImage::Format_RGB888��ͬ������ͷ�ò�ͬ�ĸ�ʽ�� 
	QImage image = QImage((const uchar*)frame->imageData, frame->width, frame->height, QImage::Format_RGB888).rgbSwapped();
	ui->label->setPixmap(QPixmap::fromImage(image));  // ��ͼƬ��ʾ��label�� 
}

/*************************
********* ���� ***********
**************************/
void Capture::takingPictures()
{
	frame = cvQueryFrame(cam);// ������ͷ��ץȡ������ÿһ֡ 

	// ��ץȡ����֡��ת��ΪQImage��ʽ��QImage::Format_RGB888��ͬ������ͷ�ò�ͬ�ĸ�ʽ�� 
	QImage image((const uchar*)frame->imageData, frame->width, frame->height, QImage::Format_RGB888);

	ui->label_2->setPixmap(QPixmap::fromImage(image));  // ��ͼƬ��ʾ��label�� 
}

/*******************************
***�ر�����ͷ���ͷ���Դ�������ͷ�***
********************************/
void Capture::closeCamera()
{
	timer->stop();         // ֹͣ��ȡ���ݡ� 

	cvReleaseCapture(&cam);//�ͷ��ڴ棻 
}

Capture::~Capture()
{
	delete ui;
}