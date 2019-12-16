//��̬����
#pragma once
#include<iostream>
#include<stdlib.h>
using namespace std;
const int maxSize = 100;//��̬�����С
struct PolyTerm{
	int coef;//ϵ��
	int exp;//ָ��
	friend ostream& operator<<(ostream&, const PolyTerm&);//����һЩҪ�õķ���
	friend bool operator ==(PolyTerm &, PolyTerm &);
	friend istream& operator>>(istream&, PolyTerm&);
	PolyTerm& operator=(PolyTerm &r) {
		this->coef = r.coef;
		this->exp = r.exp;
		return *this;
	}
};
ostream& operator<<(ostream& out, const PolyTerm& x) {
	//���һ����x�����ݵ������out��
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
	//��������in���뵥��
	int c, e;
	cout << "Input a term(coef,exp):" << endl;
	in >> c >> e;//�������ϵ��c��ָ��e
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
	PolyTerm data;				//�ڵ�����
	int link;			//�ڵ�����ָ��
};
class StaticList {
	SLinkNode elem[maxSize];//Ԫ������
	int avil;
private:
	float ValueofTerm(SLinkNode * p, float x) {
		if (p->link ==-1)return p->data.coef;
		else return (p->data.coef + x * ValueofTerm((p + 1), x));
	}//��ֵ
public:
	void InitList() {
		elem[0].link = -1; avil = 1;
		for (int i = 1; i < maxSize - 1; i++)
			elem[i].link = i + 1;
		elem[maxSize - 1].link = -1;
	}//��ʼ��
	int Length() {
		int p = elem[0].link; int i = 0;
		while (p != -1) {
			p = elem[p].link; i++;
		}
		return i;
	}//�󳤶�
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
	}//�������
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
	};//����
	void Input()//����
	{
		int num;
		cout << "��ʼ������̬��������������Ҫ��ӵ�������";
		while (1) {
			cin >> num;
			if(num>maxSize)
			cout << "����������󣬷�Χ���ܳ���" << maxSize-1<< "\n";
			else break;
		}
		for (int i = 1; i <= num; i++)										//��������Ԫ��
		{
			PolyTerm temp;
			cin >> temp;
			Append(temp); cout <<"���ǵ�" <<i <<"��"<< endl;
		}
	}
	void Random() {
		PolyTerm p;
		int e;
		srand(time(0));
		int num = rand() % 10 + 1;//����
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
	}//�����
	void Output()//���
	{
		//�������ʽ
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