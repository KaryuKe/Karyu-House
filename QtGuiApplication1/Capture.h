#include <QWidget> 
#include <QImage> 
#include <QTimer>     // 设置采集数据的间隔时间 

#include <highgui.h>  //包含opencv库头文件 
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
	void openCamera();      // 打开摄像头 
	void readFrame();       // 读取当前帧信息 
	void closeCamera();     // 关闭摄像头。 
	void takingPictures();  // 拍照 

private:
	Ui::Capture *ui;
	QTimer    *timer;
	QImage    *imag;
	CvCapture *cam;// 视频获取结构， 用来作为视频获取函数的一个参数 
	IplImage  *frame;//申请IplImage类型指针，就是申请内存空间来存放每一帧图像 
};
