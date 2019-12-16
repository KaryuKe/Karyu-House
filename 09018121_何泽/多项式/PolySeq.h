//顺序表
#pragma once
#include<iostream>
#include<stdlib.h>
#include<ctime>
#include"Linearlist.h"
using namespace std;
const int defaultSize = 100;
struct PolyNode {
	int coef;
	int exp;
	friend istream& operator>>(istream&, PolyNode &);
	friend ostream& operator<<(ostream&, const PolyNode&);
	PolyNode operator=(const PolyNode & r) {
		this->coef = r.coef;
		this->exp = r.exp;
		return *this;
	};
};

ostream& operator<<(ostream& out, const PolyNode& x) {
	//输出一个项x的内容到输出流out中
	if (x.coef == 0.0)return out;
	out << x.coef;
	switch (x.exp) {
	case 0:break;
	case 1:out << "X"; break;
	default:out << "X^" << x.exp; break;
	}
	return out;
};
istream& operator>>(istream& in, PolyNode& x) {
	//从输入流in输入单项
	int c, e;
	cout << "Input a term(coef,exp):" << endl;
	in >> c >> e;//输入项的系数c和指数e
	x.coef = c;
	x.exp = e;
	return in;
};
class SeqList :public LinearList<PolyNode> {
protected:
	PolyNode * data;											//存放数组
	int maxSize;										//最大可容纳表项的项数
	int last;											//当前已存表项的最后位置（从0开始）
	void reSize(int newSize)							//改变data数组空间大小
	{
		if (newSize <= 0)									//检查参数的合理性
		{
			cerr << "无效的数组大小" << endl; return;
		}
		if (newSize != maxSize) {						//修改
			PolyNode *newarray = new PolyNode[newSize];				//建立新数组
			if (newarray == NULL)
			{
				cerr << "存储分配错误" << endl;
				exit(1);
			}
			int n = last + 1;
			PolyNode *srcptr = data;							//源数组首地址
			PolyNode *destptr = newarray;						//目的数组首地址
			while (n--) *destptr++ = *srcptr++;			//复制
			delete[]data;								//删除老数组
			data = newarray; maxSize = newSize;			//复制新数组
		}
	}
	float ValueofTerm(PolyNode *p, float x) 
	{
		if ((p-data)==last)return p->coef;
		else return (p->coef + x * ValueofTerm((p+1), x));
	}
public:
	SeqList(int sz = defaultSize)						//构造函数
	{
		if (sz > 0) {
			maxSize = sz; last = -1;
			data = new PolyNode[maxSize];
			if (data == NULL)
			{
				cerr << "存储分配错误！" << endl;
				exit(1);
			}
		}
	}
	SeqList(SeqList& L)								//拷贝构造函数
	{
		maxSize = L.Size(); last = L.Length() - 1; PolyNode value;
		data = new PolyNode[maxSize];								//创建顺序表存储数组
		if (data == NULL)									//动态分配失败
		{
			cerr << "存储分配错误！" << endl;
			exit(1);
		}
		for (int i = 1; i <= last + 1; i++)
		{
			L.getData(i, value); data[i - 1] = value;
		}
	}
	float Calc(float x) 
	{
		//计算多项式
		PolyNode * p = data;
		if (last==-1)return 0;//判断是否为空
		else return ValueofTerm(p, x);
	}
	~SeqList() { delete[] data; }                        //析构函数
	int Size()const { return maxSize; }                  //计算表最大可容纳表项个数
	int Length()const { return last + 1; }               //计算表长度
	int Search(PolyNode& x)const								//搜索x在表中位置，函数返回表项序号
	{
		//for (int i = 0; i <= last; i++)
		//	if (data[i] == x)return i + 1;				//顺序搜索
		return 0;										//搜索失败
	}
	int Locate(int i)const								//定位第i个表项的值
	{
		if (i >= 1 && i <= last + 1) return i;
		else return 0;
	}
	PolyNode *LocateTerm(int i)const							//定位第i个表项的值
	{
		if (i >= 1 && i <= last + 1) return &data[i - 1];
		else return NULL;
	}
	bool getData(int i, PolyNode& x)const						//取第i个表项的值
	{
		if (i > 0 && i <= last + 1) { x = data[i - 1]; return true; }
		else return false;
	}
	void setData(int i, PolyNode& x)							//用x修改第i个表项的值
	{
		if (i > 0 && i <= last + 1) data[i - 1] = x;
	}
	bool Insert(int i, PolyNode& x)							//插入x在第i个表项之后
	{
		if (last == maxSize - 1)return false;					//表满，不能插入
		if (i<0 || i>last + 1)return false;						//参数i不合理，不能插入
		for (int j = last; j >= i; j--)
			data[j + 1] = data[j];								//依次后移，空出第i号位置
		data[i] = x;											//插入
		last++;													//最后位置加一
		return true;											//插入成功
	}
	bool Remove(int i, PolyNode& x)							//删除第i个表项，通过x返回表项的值
	{
		return false;											//该题用不到该功能
	}
	bool IsEmpty()const { return last == -1 ? true : false; }//判表空否，空则返回true；否则返回false
	bool IsFull()const { return last == maxSize - 1 ? true : false; }//判表满否，满则返回true；否则返回false
	void Sort() {}//排序
	void Input()//输入
	{
		cout << "开始建立顺序表，请输入表中元素个数：";
		while (1) {
			int num;
			cin >> num;
			last=num-1;													//输入元素最后位置
			if (last <= maxSize - 1)break;
			cout << "表中元素输入个数有误，范围不能超过" << maxSize - 1 << ": ";
		}
		for (int i = 0; i <= last; i++)										//逐个输入表元素
		{
			cin >> data[i]; cout <<"这是第" <<i + 1 <<"项"<< endl;
		}
	}
	void Random() {
		PolyNode* p = data;
		int e;
		srand(time(0));
		int num = rand() % 10+1;//项数
		int c = rand() % 100;
		e = rand() % 100;
		p->coef = c;
		p->exp = e;
		for (int i = 1; i < num; i++) {
			int c = rand() % 100;
			
			while (1) {
				srand(time(0));
				int temp = rand() % 500;
				if (temp > p->exp)
				{
					e = temp;
					break;
				}
			}
			p++;
			last++;
			p->exp = e;
			p->coef = c;
		}
	}
	void Output()//输出
	{
		//输出多项式
		PolyNode * p = data;
		cout << "The polynomial is:" << endl;
		bool h = true;
		while (p-data<=last) {
			if (h == false && p->coef > 0.0)
				cout << "+";
			h = false;
			cout << *p;//调用PolyNode类的重载操作“<<”
			p++;
		}
		cout << endl;
	}
	SeqList operator=(SeqList& L) //表整体赋值
	{
		delete[]data;

		maxSize = L.Size(); last = L.Length() - 1; PolyNode value;
		data = new PolyNode[maxSize];								//创建顺序表存储数组
		if (data == NULL)									//动态分配失败
		{
			cerr << "存储分配错误！" << endl;
			exit(1);
		}
		for (int i = 1; i <= last + 1; i++)
		{
			L.getData(i, value); data[i - 1] = value;
		}
	}
};
