#include <iostream>
#include "limits.h"
#include <algorithm>
using namespace std;
int maxInt = INT_MAX;
int fm = 1;
int n = 1;
int m = 1;
void maxfac()
{
	int result = 1;
	for (; fm <= maxInt / result; result++)
	{
		fm *= result;
	}
	m = --result;
	cout << "\nm=" << result << "\nm!=" << fm;
}
void maxpower2()
{
	bool flag = 0;
	int p=1;
	for (;;n++) 
	{
			p *= 2;
			//cout << p << endl;
			if (p > maxInt/2)
			{
				cout << "\nn=" << n << "\n2^n=" << p << endl;
				break;
			}
	}
	
}
void calc()
{
	int maxSize = min(m, n);
	int * A = new int [maxSize] ;
	int f = 1;
	int p = 1;
	unsigned long long nextRes;
	A[0] = 1;
	int count = 0;
	int time = 0;
	for (int i = 1;; i++)
	{
		f *= i;
		p *= 2;
		A[i] = f * p;
		nextRes = A[i] * (i + 1) * 2;
		count++;
		if (nextRes > maxInt)
			break;
	}
	for (int m = 0; m < count+1; m++)
	{
		cout << A[m] << " ";
		time++;
		if (time % 10 == 0)
			cout << "\n";
	}
} 
int main() 
{
	cout << "maxInt=" << maxInt;
	maxfac();
	maxpower2();
	calc();
	system("pause");
}