//静态链表
#pragma once
#include<iostream>
#include<stdlib.h>
using namespace std;
const int maxSize = 100;//静态链表大小
struct PolyTerm{
	int coef;//系数
	int exp;//指数
	friend ostream& operator<<(ostream&, const PolyTerm&);//重载一些要用的符号
	friend bool operator ==(PolyTerm &, PolyTerm &);
	friend istream& operator>>(istream&, PolyTerm&);
	PolyTerm& operator=(PolyTerm &r) {
		this->coef = r.coef;
		this->exp = r.exp;
		return *this;
	}
};
ostream& operator<<(ostream& out, const PolyTerm& x) {
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
istream& operator>>(istream& in, PolyTerm& x) {
	//从输入流in输入单项
	int c, e;
	cout << "Input a term(coef,exp):" << endl;
	in >> c >> e;//输入项的系数c和指数e
	x.coef = c;
	x.exp = e;
	return in;
}
bool operator==(PolyTerm & l,PolyTerm& r)
{
	if (l.coef == r.coef&&l.exp == r.exp)
		return true;
	return false;
};

struct SLinkNode {
	PolyTerm data;				//节点数据
	int link;			//节点链接指针
};
class StaticList {
	SLinkNode elem[maxSize];//元素数组
	int avil;
private:
	float ValueofTerm(SLinkNode * p, float x) {
		if (p->link ==-1)return p->data.coef;
		else return (p->data.coef + x * ValueofTerm((p + 1), x));
	}//求值
public:
	void InitList() {
		elem[0].link = -1; avil = 1;
		for (int i = 1; i < maxSize - 1; i++)
			elem[i].link = i + 1;
		elem[maxSize - 1].link = -1;
	}//初始化
	int Length() {
		int p = elem[0].link; int i = 0;
		while (p != -1) {
			p = elem[p].link; i++;
		}
		return i;
	}//求长度
	int Search(PolyTerm x) {
		int p = elem[0].link;
		while (p != -1)
			if (elem[p].data == x)break;
			else p = elem[p].link;
		return p;
	}
	int Locate(int i) {
		if (i < 0)return -1;
		if (i == 0) return 0;
		int j = 1, p = elem[0].link;
		while(p!=-1&&j<i)
		{
			p = elem[p].link; j++;
		}
		return p;
	}
	bool Append(PolyTerm x) {
		if (avil == -1)return false;
		int q = avil;
		avil = elem[avil].link;
		elem[q].data = x;
		elem[q].link = -1;
		int p = 0;
		while (elem[p].link != -1)
			p = elem[p].link;
		elem[p].link = q;
		return true;
	}//向后增加
	bool Insert(int i, PolyTerm x) {
		int p = Locate(i);
		if (p == -1)return false;
		int q = avil;
		avil = elem[avil].link;
		elem[q].data = x;
		elem[q].link = elem[p].link;
		elem[p].link = q;
		return true;
	}
	bool Remove(int i) {
		int p = Locate(i - 1);
		if (p == -1)return false;
		int q = elem[p].link;
		elem[p].link = elem[q].link;
		elem[q].link = avil;
		avil = q;
		return true;
	}
	bool IsEmpty() {
		if (elem[0].link == -1)return true;
		else return false;
	}
	float Calc(float x) {
		SLinkNode* p = elem;
		if (this->Length() == 0)return 0;
		else return ValueofTerm(p+1, x);
	};//计算
	void Input()//输入
	{
		int num;
		cout << "开始建立静态链表，请输入你想要添加的项数：";
		while (1) {
			cin >> num;
			if(num>maxSize)
			cout << "输入个数有误，范围不能超过" << maxSize-1<< "\n";
			else break;
		}
		for (int i = 1; i <= num; i++)										//逐个输入表元素
		{
			PolyTerm temp;
			cin >> temp;
			Append(temp); cout <<"这是第" <<i <<"项"<< endl;
		}
	}
	void Random() {
		PolyTerm p;
		int e;
		srand(time(0));
		int num = rand() % 10 + 1;//项数
		int c = rand() % 100;
		e = rand() % 10;
		p.exp = e;
		p.coef = c;
		Append(p);
		for (int i = 1; i < num; i++) {
			int c = rand() % 100;
			p.coef = c;
			while (1) {
				srand(time(0));
				int temp = rand() % 200;
				if (temp > p.exp)
				{
					p.exp = temp;
					break;
				}
			}
			Append(p);
		}
	}//随机化
	void Output()//输出
	{
		//输出多项式
		cout << "The polynomial is:" << endl;
		bool h = true;
		for(int i=1;i<=this->Length();i++) {
			if (h == false && elem[i].data.coef > 0.0)
				cout << "+";
			h = false;
			cout << elem[i].data;
		}
		cout << endl;
	}
};