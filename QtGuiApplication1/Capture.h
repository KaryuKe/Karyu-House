#include <QWidget> 
#include <QImage> 
#include <QTimer>     // ���òɼ����ݵļ��ʱ�� 

#include <highgui.h>  //����opencv��ͷ�ļ� 
#include <cv.h> 

namespace Ui {
	class Capture;
}

class Capture : public QWidget
{
	Q_OBJECT

public:
	explicit Capture(QWidget *parent = 0);
	~Capture();

private slots:
	void openCamera();      // ������ͷ 
	void readFrame();       // ��ȡ��ǰ֡��Ϣ 
	void closeCamera();     // �ر�����ͷ�� 
	void takingPictures();  // ���� 

private:
	Ui::Capture *ui;
	QTimer    *timer;
	QImage    *imag;
	CvCapture *cam;// ��Ƶ��ȡ�ṹ�� ������Ϊ��Ƶ��ȡ������һ������ 
	IplImage  *frame;//����IplImage����ָ�룬���������ڴ�ռ������ÿһ֡ͼ�� 
};
