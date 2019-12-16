//˳���
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
istream& operator>>(istream& in, PolyNode& x) {
	//��������in���뵥��
	int c, e;
	cout << "Input a term(coef,exp):" << endl;
	in >> c >> e;//�������ϵ��c��ָ��e
	x.coef = c;
	x.exp = e;
	return in;
};
class SeqList :public LinearList<PolyNode> {
protected:
	PolyNode * data;											//�������
	int maxSize;										//�������ɱ��������
	int last;											//��ǰ�Ѵ��������λ�ã���0��ʼ��
	void reSize(int newSize)							//�ı�data����ռ��С
	{
		if (newSize <= 0)									//�������ĺ�����
		{
			cerr << "��Ч�������С" << endl; return;
		}
		if (newSize != maxSize) {						//�޸�
			PolyNode *newarray = new PolyNode[newSize];				//����������
			if (newarray == NULL)
			{
				cerr << "�洢�������" << endl;
				exit(1);
			}
			int n = last + 1;
			PolyNode *srcptr = data;							//Դ�����׵�ַ
			PolyNode *destptr = newarray;						//Ŀ�������׵�ַ
			while (n--) *destptr++ = *srcptr++;			//����
			delete[]data;								//ɾ��������
			data = newarray; maxSize = newSize;			//����������
		}
	}
	float ValueofTerm(PolyNode *p, float x) 
	{
		if ((p-data)==last)return p->coef;
		else return (p->coef + x * ValueofTerm((p+1), x));
	}
public:
	SeqList(int sz = defaultSize)						//���캯��
	{
		if (sz > 0) {
			maxSize = sz; last = -1;
			data = new PolyNode[maxSize];
			if (data == NULL)
			{
				cerr << "�洢�������" << endl;
				exit(1);
			}
		}
	}
	SeqList(SeqList& L)								//�������캯��
	{
		maxSize = L.Size(); last = L.Length() - 1; PolyNode value;
		data = new PolyNode[maxSize];								//����˳���洢����
		if (data == NULL)									//��̬����ʧ��
		{
			cerr << "�洢�������" << endl;
			exit(1);
		}
		for (int i = 1; i <= last + 1; i++)
		{
			L.getData(i, value); data[i - 1] = value;
		}
	}
	float Calc(float x) 
	{
		//�������ʽ
		PolyNode * p = data;
		if (last==-1)return 0;//�ж��Ƿ�Ϊ��
		else return ValueofTerm(p, x);
	}
	~SeqList() { delete[] data; }                        //��������
	int Size()const { return maxSize; }                  //������������ɱ������
	int Length()const { return last + 1; }               //�������
	int Search(PolyNode& x)const								//����x�ڱ���λ�ã��������ر������
	{
		//for (int i = 0; i <= last; i++)
		//	if (data[i] == x)return i + 1;				//˳������
		return 0;										//����ʧ��
	}
	int Locate(int i)const								//��λ��i�������ֵ
	{
		if (i >= 1 && i <= last + 1) return i;
		else return 0;
	}
	PolyNode *LocateTerm(int i)const							//��λ��i�������ֵ
	{
		if (i >= 1 && i <= last + 1) return &data[i - 1];
		else return NULL;
	}
	bool getData(int i, PolyNode& x)const						//ȡ��i�������ֵ
	{
		if (i > 0 && i <= last + 1) { x = data[i - 1]; return true; }
		else return false;
	}
	void setData(int i, PolyNode& x)							//��x�޸ĵ�i�������ֵ
	{
		if (i > 0 && i <= last + 1) data[i - 1] = x;
	}
	bool Insert(int i, PolyNode& x)							//����x�ڵ�i������֮��
	{
		if (last == maxSize - 1)return false;					//���������ܲ���
		if (i<0 || i>last + 1)return false;						//����i���������ܲ���
		for (int j = last; j >= i; j--)
			data[j + 1] = data[j];								//���κ��ƣ��ճ���i��λ��
		data[i] = x;											//����
		last++;													//���λ�ü�һ
		return true;											//����ɹ�
	}
	bool Remove(int i, PolyNode& x)							//ɾ����i�����ͨ��x���ر����ֵ
	{
		return false;											//�����ò����ù���
	}
	bool IsEmpty()const { return last == -1 ? true : false; }//�б�շ񣬿��򷵻�true�����򷵻�false
	bool IsFull()const { return last == maxSize - 1 ? true : false; }//�б��������򷵻�true�����򷵻�false
	void Sort() {}//����
	void Input()//����
	{
		cout << "��ʼ����˳������������Ԫ�ظ�����";
		while (1) {
			int num;
			cin >> num;
			last=num-1;													//����Ԫ�����λ��
			if (last <= maxSize - 1)break;
			cout << "����Ԫ������������󣬷�Χ���ܳ���" << maxSize - 1 << ": ";
		}
		for (int i = 0; i <= last; i++)										//��������Ԫ��
		{
			cin >> data[i]; cout <<"���ǵ�" <<i + 1 <<"��"<< endl;
		}
	}
	void Random() {
		PolyNode* p = data;
		int e;
		srand(time(0));
		int num = rand() % 10+1;//����
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
	void Output()//���
	{
		//�������ʽ
		PolyNode * p = data;
		cout << "The polynomial is:" << endl;
		bool h = true;
		while (p-data<=last) {
			if (h == false && p->coef > 0.0)
				cout << "+";
			h = false;
			cout << *p;//����PolyNode������ز�����<<��
			p++;
		}
		cout << endl;
	}
	SeqList operator=(SeqList& L) //�����帳ֵ
	{
		delete[]data;

		maxSize = L.Size(); last = L.Length() - 1; PolyNode value;
		data = new PolyNode[maxSize];								//����˳���洢����
		if (data == NULL)									//��̬����ʧ��
		{
			cerr << "�洢�������" << endl;
			exit(1);
		}
		for (int i = 1; i <= last + 1; i++)
		{
			L.getData(i, value); data[i - 1] = value;
		}
	}
};
