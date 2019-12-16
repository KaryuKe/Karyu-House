#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
using namespace std;
#define M 12
long Fib_1(int n)//�ݹ鷨��Fibonacci����
{
	return (n < 2) ? n : Fib_1(n - 1) + Fib_1(n - 2);

}
long Fib_2(int n)//��������Fibonacci����
{

	if (n < 2)
		return n;
	int i = 1;
	int fib1 = 0, fib2 = 1, fib = 0;
	while (i < n)
	{
		fib = fib1 + fib2;
		fib1 = fib2;
		fib2 = fib;
		i++;
	}
	return fib;
}
void execCH1_2()
{
	int i, k;
	int fib_item;
	int item[M] = { 10,15,20,25,30,35,40,41,42,43,44,45 };
	clock_t start, stop;
	cout << "ѡ���㷨��1��ʾ�ݹ鷨��2��ʾ��������";
	cin >> k;
	if (k != 1 && k != 2) {
		cout << "ѡ�����������\n";
		exit(1);
	}
	if (k == 1)
		cout << "�ݹ��㷨��";
	else
		cout << "�����㷨��";
	cout << "�ٶ�����n��ȡֵΪ{10,15,20,25,30,35,40,41,42,43,44,45}\n";
	//�����㷨
	if (k == 1)
	{
		for (i = 0; i < 12; i++)
		{
			start = clock();
			fib_item = Fib_1(item[i]);
			stop = clock();
			cout << "Fib(" << item[i] << ")= " << setiosflags(ios::left) << setw(10) << fib_item << "���β����㷨ʱ�俪���� " << fixed << setprecision(3) << ((double)(stop - start) / CLK_TCK) << endl;
		}
	}
	else
	{
		for (i = 0; i < 12; i++)
		{
			start = clock();
			fib_item = Fib_2(item[i]);
			stop = clock();
			cout << "Fib(" << item[i] << ")= " << setiosflags(ios::left) << setw(10) << fib_item << "���β����㷨ʱ�俪���� " << fixed << setprecision(3) << ((double)(stop - start) / CLK_TCK) << endl;
		}
	}
}
int main()
{
	execCH1_2();
	cout << "���ڲ������ɼ���Fibonacci����������";
	for (int n = 10;; n++) {
		int b=Fib_2(n);
		if (b < 0) {
			cout << "\n���" << (n - 1) << "�";
			break;
		}
	}
	system("pause");
}