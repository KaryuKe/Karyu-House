#include<iostream>
#include"Ex2.h"
int main()
{
	Ex2 e1(1, "Bob Jones", 34500);
	Ex2 e2(2, "Susan Baker", 37800);
	e1.displayMessage();
	e2.displayMessage();
	cout << "Increasing employee salaries by 10%" << endl;
	e1.setMoney(e1.getMoney()*1.1);
	e2.setMoney(e2.getMoney()*1.1);
	e1.displayMessage();
	e2.displayMessage();
	system("pause");
}