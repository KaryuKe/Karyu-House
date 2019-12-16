
#include <iostream>  
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  

using namespace cv;

int main()
{
	VideoCapture cap;
	cap.open(0); // 打开视频捕捉
	if (!cap.isOpened()) { // 检查是否打开摄像头
		std::cerr << "无法打开摄像头。" << std::endl;
		return -1;
	}
	Mat frame;
	for (;;) {
		cap >> frame;
		if (frame.empty()) break; // Ran out of film
		cv::imshow("摄像机", frame);
	}
destroyAllWindows();
}