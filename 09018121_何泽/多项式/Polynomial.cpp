//���ļ�
#include"Polynomialinked.h"
#include"PolySeq.h"
#include"PolyStatic.h"
#include<iostream>
#include<ctime>
using namespace std;
void calcLinked() {
	Polynomial a;
	Term * p = a.getHead();
	float x;
	int option;
	cout << "��������ѡ��1.������ɶ���ʽ2.�ֶ��������ʽ������";
	cin >> option;
	if (option == 2) {
		cin >> a;
		cout << a<<"������x��ֵ" << endl;
		cin >> x;
		cout<< "\n�ö���ʽ��ֵΪ��" << a.Calc(x) << endl;
	}
	else if(option==1)
	{
		int e;
		srand(time(0));
		int num = rand() % 10+1;//����
		for (int i = 0; i < num; i++) {
			int c = rand() % 100;
			while (1) {
				srand(time(0));
				int temp = rand() % 200;
				if (temp > p->exp)
				{
					e = temp;
					break;
				}
			}
			p = p->InsertAfter(c,e);
		}
		cout << a;
		cout << "������x��ֵ" << endl;
		cin >> x;
		cout<<"\n�ö���ʽ��ֵΪ��" << a.Calc(x) << endl;
	}
	else cout << "�������";
}
void calcSeq() {
	SeqList a;
	float x;
	int option;
	cout << "˳�����ѡ��1.������ɶ���ʽ2.�ֶ��������ʽ������";
	cin >> option;
	if (option == 2) {
		a.Input();
		a.Output();
		cout<< "������x��ֵ" << endl;
		cin >> x;
		cout << "\n�ö���ʽ��ֵΪ��" << a.Calc(x) << endl;
	}
	else if (option == 1)
	{
		a.Random();
		a.Output();
		cout << "������x��ֵ" << endl;
		cin >> x;
		cout << "�ö���ʽ��ֵΪ��" << a.Calc(x) << endl;
	}
	else cout << "�������";
}
void calcStatic() {
	StaticList a;
	a.InitList();
	float x;
	int option;
	cout << "��̬������ѡ��1.������ɶ���ʽ2.�ֶ��������ʽ������";
	cin >> option;
	if (option == 2) {
		a.Input();
		a.Output();
		cout << "������x��ֵ" << endl;
		cin >> x;
		cout << "\n�ö���ʽ��ֵΪ��" << a.Calc(x) << endl;
	}
	else if (option == 1)
	{
		a.Random();
		a.Output();
		cout << "������x��ֵ" << endl;
		cin >> x;
		cout << "�ö���ʽ��ֵΪ��" << a.Calc(x) << endl;
	}
	else cout << "�������";
}
int main()
{
	int method;
	cout << "��ѡ��ʹ�õķ�����1.˳���2.������3.��̬��";
	cin >> method;
	if (method == 1)
		calcSeq();
	else if (method == 2)
		calcLinked();
	else if (method == 3)
		calcStatic();
	else
		cout << "�������";
	system("pause");
}