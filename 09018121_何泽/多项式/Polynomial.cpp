//主文件
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
	cout << "单链表。请选择1.随机生成多项式2.手动输入多项式（升序）";
	cin >> option;
	if (option == 2) {
		cin >> a;
		cout << a<<"请输入x的值" << endl;
		cin >> x;
		cout<< "\n该多项式的值为：" << a.Calc(x) << endl;
	}
	else if(option==1)
	{
		int e;
		srand(time(0));
		int num = rand() % 10+1;//项数
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
		cout << "请输入x的值" << endl;
		cin >> x;
		cout<<"\n该多项式的值为：" << a.Calc(x) << endl;
	}
	else cout << "输入错误！";
}
void calcSeq() {
	SeqList a;
	float x;
	int option;
	cout << "顺序表。请选择1.随机生成多项式2.手动输入多项式（升序）";
	cin >> option;
	if (option == 2) {
		a.Input();
		a.Output();
		cout<< "请输入x的值" << endl;
		cin >> x;
		cout << "\n该多项式的值为：" << a.Calc(x) << endl;
	}
	else if (option == 1)
	{
		a.Random();
		a.Output();
		cout << "请输入x的值" << endl;
		cin >> x;
		cout << "该多项式的值为：" << a.Calc(x) << endl;
	}
	else cout << "输入错误！";
}
void calcStatic() {
	StaticList a;
	a.InitList();
	float x;
	int option;
	cout << "静态链表。请选择1.随机生成多项式2.手动输入多项式（升序）";
	cin >> option;
	if (option == 2) {
		a.Input();
		a.Output();
		cout << "请输入x的值" << endl;
		cin >> x;
		cout << "\n该多项式的值为：" << a.Calc(x) << endl;
	}
	else if (option == 1)
	{
		a.Random();
		a.Output();
		cout << "请输入x的值" << endl;
		cin >> x;
		cout << "该多项式的值为：" << a.Calc(x) << endl;
	}
	else cout << "输入错误！";
}
int main()
{
	int method;
	cout << "请选择使用的方法。1.顺序表。2.单链表。3.静态表。";
	cin >> method;
	if (method == 1)
		calcSeq();
	else if (method == 2)
		calcLinked();
	else if (method == 3)
		calcStatic();
	else
		cout << "输入错误！";
	system("pause");
}