#include<iostream>
#include "Invoice.h"
using namespace std;
int main()
{
	Invoice in1("1","Princess Xixi", 90, 10);
	cout <<"Item Number "<<in1.getNumber()<< "," << in1.getDescription() << "'s invoice amount is " << in1.getInvoiceAmount(in1.getPrice(), in1.getSale()) << " dollar." << endl;
	system("pause");
}