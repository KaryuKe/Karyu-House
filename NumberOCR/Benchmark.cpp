//使用线性SVM
#include <opencv/cv.h>  
#include <opencv2/opencv.hpp>  
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/ml/ml.hpp>  
#include <io.h>
#include <iostream> 
#include "Detect.h"
#include<ctime>
#include<cstdlib>
using namespace std;
using namespace cv;
using namespace ml;
Detect a;
void test(int n)
{
	int result = 0;
	string s = "./TestSample/" + to_string(n);
	const char * path = s.c_str();
	vector<string> files;
	a.getFilePath(path, files);
	int number = files.size();
	//cout << number << endl;
	string modelpath = "./svm.xml";
	Ptr<SVM> svm = StatModel::load<SVM>(modelpath);
	clock_t start = clock();
	for (int i = 0; i < number; i++)
	{
		Mat inMat = imread(files[i].c_str(), 0);
		//cout << files[i].c_str()<<endl;
		resize(inMat, inMat, Size(8, 16), (0, 0), (0, 0), INTER_AREA);
		Mat p = inMat.reshape(1, 1);
		p.convertTo(p, CV_32FC1);
		int response = (int)svm->predict(p);
		cout << response << endl;
		if (response == n)
		{
			result++;
		}
	}
	clock_t stop = clock();
	if(n>0)
	cout << "对数字" << n << "的识别率为" << result / number * 100 << "%" << "，共"<<number<<"张图片，用时"<< setprecision(3) << ((double)(stop - start) / CLK_TCK) << "秒"<<endl;
	else
		cout<<"对负样本" << "的识别率为" << result / number * 100 << "%" << "，共" << number << "张图片，用时" << setprecision(3) << ((double)(stop - start) / CLK_TCK) << "秒" << endl;

}
int main()
{
	a.detect();
	for (int n = 1; n <= 5; n++)
		test(n);
	test(-1);
	system("pause");
}