//使用VS2017
#pragma   once  
#include <opencv/cv.h>  
#include <opencv2/opencv.hpp>  
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/ml/ml.hpp>  
#include <io.h>
#include <iostream> 

using namespace std;
using namespace cv;
using namespace ml;

class Detect {
public:
	void getFilePath(string path, vector<string>& files)
	{
		long long hFile = 0;//文件句柄
		struct _finddata_t fileinfo;//文件信息
		string p;
		if ((hFile = _findfirst(p.assign(path).append("/*").c_str(), &fileinfo)) != -1)//判断是否为空，初始化fileinfo
			//如果查找到第一个文件
		{
			do
			{
				if ((fileinfo.attrib &  _A_SUBDIR))//文件夹的情况
				{
					if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
						getFilePath(p.assign(path).append("/").append(fileinfo.name), files);
				}
				else//文件的情况
				{
					files.push_back(p.assign(path).append("/").append(fileinfo.name));
				}
			} while (_findnext(hFile, &fileinfo) == 0);//还能继续寻找文件时继续

			_findclose(hFile);//结束查找，关闭句柄。
		}
	}
	void TrainNum1(Mat& Image, vector<int>& label)//训练数字1
	{
		char * filePath = (char*)"./Sample/1";//选择路径
		vector<string> filename;
		getFilePath(filePath, filename);//将文件路径存至vector中
		int number = filename.size();
		for (int i = 0; i < number; i++)//循环文件个数次
		{
			Mat  OrginalImage = imread(filename[i].c_str(), 0);//打开图片
			resize(OrginalImage, OrginalImage, Size(8, 16), (0, 0), (0, 0), INTER_AREA);//选择INTER_AREA的插值方法来进行图像抽取
			OrginalImage = OrginalImage.reshape(1, 1);//通道数、矩阵行数改为1
			Image.push_back(OrginalImage);
			label.push_back(1);
		}
	}
	void TrainNum2(Mat& Image, vector<int>& label)//训练数字2的样本
	{
		char * filePath = (char*)"./Sample/2";
		vector<string> filename;
		getFilePath(filePath, filename);
		int number = filename.size();
		for (int i = 0; i < number; i++)
		{
			Mat  OrginalImage = imread(filename[i].c_str(), 0);
			resize(OrginalImage, OrginalImage, Size(8, 16), (0, 0), (0, 0), INTER_AREA);
			OrginalImage = OrginalImage.reshape(1, 1);
			Image.push_back(OrginalImage);
			label.push_back(2);
		}
	}
	void TrainNum3(Mat& Image, vector<int>& label)//训练数字3
	{
		char * filePath = (char*)"./Sample/3";
		vector<string> filename;
		getFilePath(filePath, filename);
		int number = filename.size();
		for (int i = 0; i < number; i++)
		{
			Mat  OrginalImage = imread(filename[i].c_str(), 0);
			resize(OrginalImage, OrginalImage, Size(8, 16), (0, 0), (0, 0), INTER_AREA);
			OrginalImage = OrginalImage.reshape(1, 1);
			Image.push_back(OrginalImage);
			label.push_back(3);
		}
	}
	void TrainNum4(Mat& Image, vector<int>& label)//训练数字4
	{
		char * filePath = (char*)"./Sample/4";
		vector<string> filename;
		getFilePath(filePath, filename);
		int number = filename.size();
		for (int i = 0; i < number; i++)
		{
			Mat  OrginalImage = imread(filename[i].c_str(), 0);
			resize(OrginalImage, OrginalImage, Size(8, 16), (0, 0), (0, 0), INTER_AREA);
			OrginalImage = OrginalImage.reshape(1, 1);
			Image.push_back(OrginalImage);
			label.push_back(4);
		}
	}
	void TrainNum5(Mat& Image, vector<int>& label)//训练数字5
	{
		char * filePath = (char*)"./Sample/5";
		vector<string> filename;
		getFilePath(filePath, filename);
		int number = filename.size();
		for (int i = 0; i < number; i++)
		{
			Mat  OrginalImage = imread(filename[i].c_str(), 0);
			resize(OrginalImage, OrginalImage, Size(8, 16), (0, 0), (0, 0), INTER_AREA);
			OrginalImage = OrginalImage.reshape(1, 1);
			Image.push_back(OrginalImage);
			label.push_back(5);
		}
	}
	void TrainOthers(Mat& Image, vector<int>& label)//训练负样本
	{
		char * filePath = (char*)"./Sample/-1";
		vector<string> filename;
		getFilePath(filePath, filename);
		int number = filename.size();
		for (int i = 0; i < number; i++)
		{
			Mat  OrginalImage = imread(filename[i].c_str(), 0);
			resize(OrginalImage, OrginalImage, Size(8, 16), (0, 0), (0, 0), INTER_AREA);
			OrginalImage = OrginalImage.reshape(1, 1);
			Image.push_back(OrginalImage);
			label.push_back(-1);
		}
	}
	void detect()
	{
		Mat trainedLabel;
		Mat trainedImage;
		Mat Images;
		vector<int> trainingLabels;
		TrainNum1(Images, trainingLabels);
		TrainNum2(Images, trainingLabels);
		TrainNum3(Images, trainingLabels);
		TrainNum4(Images, trainingLabels);
		TrainNum5(Images, trainingLabels);
		TrainOthers(Images, trainingLabels);//训练
		Mat(Images).copyTo(trainedImage);
		trainedImage.convertTo(trainedImage, CV_32FC1);//转换为32位浮点型单通道矩阵
		Mat(trainingLabels).copyTo(trainedLabel);
		Ptr<SVM> svm = SVM::create();//建立SVM
		svm->setKernel(SVM::LINEAR);//线性核,不进行任何映射,而是在原始特征空间中进行线性判别,速度最快。
		svm->train(trainedImage, 0, trainedLabel);//进行训练，是行型的sample，0
		svm->save("./svm.xml");//将模型保存
		cout << "训练完成" << endl;
	}
};