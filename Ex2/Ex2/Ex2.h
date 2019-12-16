#pragma once
#include <iostream>
#include <string>
using namespace std;
class Ex2
{
public:
	void setName(string);
	Ex2(int,string, int);
	void setMoney(int);
	void setRank(int);
	string getName();
	int getMoney();
	int getRank();
	void displayMessage();
private:
	string name;
	int money;
	int rank;
};