//ʹ��VS2017
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
		long long hFile = 0;//�ļ����
		struct _finddata_t fileinfo;//�ļ���Ϣ
		string p;
		if ((hFile = _findfirst(p.assign(path).append("/*").c_str(), &fileinfo)) != -1)//�ж��Ƿ�Ϊ�գ���ʼ��fileinfo
			//������ҵ���һ���ļ�
		{
			do
			{
				if ((fileinfo.attrib &  _A_SUBDIR))//�ļ��е����
				{
					if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
						getFilePath(p.assign(path).append("/").append(fileinfo.name), files);
				}
				else//�ļ������
				{
					files.push_back(p.assign(path).append("/").append(fileinfo.name));
				}
			} while (_findnext(hFile, &fileinfo) == 0);//���ܼ���Ѱ���ļ�ʱ����

			_findclose(hFile);//�������ң��رվ����
		}
	}
	void TrainNum1(Mat& Image, vector<int>& label)//ѵ������1
	{
		char * filePath = (char*)"./Sample/1";//ѡ��·��
		vector<string> filename;
		getFilePath(filePath, filename);//���ļ�·������vector��
		int number = filename.size();
		for (int i = 0; i < number; i++)//ѭ���ļ�������
		{
			Mat  OrginalImage = imread(filename[i].c_str(), 0);//��ͼƬ
			resize(OrginalImage, OrginalImage, Size(8, 16), (0, 0), (0, 0), INTER_AREA);//ѡ��INTER_AREA�Ĳ�ֵ����������ͼ���ȡ
			OrginalImage = OrginalImage.reshape(1, 1);//ͨ����������������Ϊ1
			Image.push_back(OrginalImage);
			label.push_back(1);
		}
	}
	void TrainNum2(Mat& Image, vector<int>& label)//ѵ������2������
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
	void TrainNum3(Mat& Image, vector<int>& label)//ѵ������3
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
	void TrainNum4(Mat& Image, vector<int>& label)//ѵ������4
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
	void TrainNum5(Mat& Image, vector<int>& label)//ѵ������5
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
	void TrainOthers(Mat& Image, vector<int>& label)//ѵ��������
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
		TrainOthers(Images, trainingLabels);//ѵ��
		Mat(Images).copyTo(trainedImage);
		trainedImage.convertTo(trainedImage, CV_32FC1);//ת��Ϊ32λ�����͵�ͨ������
		Mat(trainingLabels).copyTo(trainedLabel);
		Ptr<SVM> svm = SVM::create();//����SVM
		svm->setKernel(SVM::LINEAR);//���Ժ�,�������κ�ӳ��,������ԭʼ�����ռ��н��������б�,�ٶ���졣
		svm->train(trainedImage, 0, trainedLabel);//����ѵ���������͵�sample��0
		svm->save("./svm.xml");//��ģ�ͱ���
		cout << "ѵ�����" << endl;
	}
};