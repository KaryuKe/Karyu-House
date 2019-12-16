#include <iostream>
#include "Ex2.h"
using namespace std;
Ex2::Ex2(int rank1,string name1, int money1)
{
	setMoney(money1);
	setName(name1);
	setRank(rank1);
}
void Ex2::setMoney(int money1)
{
	money = money1;
}
void Ex2::setName(string name1)
{
	name = name1;
}
void Ex2::setRank(int rank1)
{
	rank = rank1;
}
int Ex2::getMoney()
{
	return money;
}
string Ex2::getName()
{
	return name;
}
int Ex2::getRank()
{
	return rank;
}
void Ex2::displayMessage()
{
	cout << "Employee " << getRank() << ":"<<getName() << "; Yearly Salary: " << getMoney() << endl;
}