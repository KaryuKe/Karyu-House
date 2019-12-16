#include<iostream>
#include "invoice.h"
#include<string>
using namespace std;
Invoice::Invoice(string num1, string des1, int sale1, int price1)
{
	setNumber(num1);
	setDescription(des1);
	setSale(sale1);
	setPrice(price1);
}
void Invoice::setNumber(string num1)
{
	number = num1;
}
void Invoice::setDescription(string des1)
{
	description = des1;
}
void Invoice::setSale(int sale1)
{
	if (sale1 >= 0) 
	{
		sale = sale1;
	}
	else
		sale = 0;
}
string Invoice::getDescription()
{
	return description;
}
string Invoice::getNumber()
{
	return number;
}
int Invoice::getPrice()
{
	return price;
}
int Invoice::getSale()
{
	return sale;
}
int Invoice::getInvoiceAmount(int price2,int sale2)
{
	amount = price2 * sale2;
	return amount;
}
void Invoice::setPrice(int price1)
{
	if (price1 >= 0) 
	{
		price = price1;
	}
	else
		price = 0;
}