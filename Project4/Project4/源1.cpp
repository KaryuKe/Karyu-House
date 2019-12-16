#include<iostream>
#include"Time.h"
using namespace std;
int main()
{
	Time t1(23, 59, 57);
	t1.printStandard();
	for (int i = 0; i <= 10; i++)
	{
		tick(t1);
		cout << "\n";
		t1.printStandard();
	}
}