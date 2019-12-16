#pragma once
#include<iostream>
#include<string>
using namespace std;
class Invoice
{
public:
	Invoice(string, string, int, int);
	void setNumber(string);
	string getNumber();
	void setDescription(string);
	string getDescription();
	void setSale(int);
	int getSale();
	void setPrice(int);
	int getPrice();
	int getInvoiceAmount(int,int);
private:
	string number;
	string description;
	int sale;
	int price;
	int amount;
};
