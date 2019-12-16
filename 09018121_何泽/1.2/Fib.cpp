#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
using namespace std;
#define M 12
long Fib_1(int n)//递归法求Fibonacci数列
{
	return (n < 2) ? n : Fib_1(n - 1) + Fib_1(n - 2);

}
long Fib_2(int n)//迭代法求Fibonacci数列
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
	cout << "选择算法，1表示递归法，2表示迭代法：";
	cin >> k;
	if (k != 1 && k != 2) {
		cout << "选择项输入错误。\n";
		exit(1);
	}
	if (k == 1)
		cout << "递归算法，";
	else
		cout << "迭代算法，";
	cout << "假定测试n的取值为{10,15,20,25,30,35,40,41,42,43,44,45}\n";
	//测试算法
	if (k == 1)
	{
		for (i = 0; i < 12; i++)
		{
			start = clock();
			fib_item = Fib_1(item[i]);
			stop = clock();
			cout << "Fib(" << item[i] << ")= " << setiosflags(ios::left) << setw(10) << fib_item << "本次测试算法时间开销： " << fixed << setprecision(3) << ((double)(stop - start) / CLK_TCK) << endl;
		}
	}
	else
	{
		for (i = 0; i < 12; i++)
		{
			start = clock();
			fib_item = Fib_2(item[i]);
			stop = clock();
			cout << "Fib(" << item[i] << ")= " << setiosflags(ios::left) << setw(10) << fib_item << "本次测试算法时间开销： " << fixed << setprecision(3) << ((double)(stop - start) / CLK_TCK) << endl;
		}
	}
}
int main()
{
	execCH1_2();
	cout << "现在测试最大可计算Fibonacci数列项数。";
	for (int n = 10;; n++) {
		int b=Fib_2(n);
		if (b < 0) {
			cout << "\n最多" << (n - 1) << "项。";
			break;
		}
	}
	system("pause");
}