#include"LinkedList.h"
#include<ctime>
#include<cstdlib>
#include<iostream>
using namespace std;
int main()
{	List list;
	int num, limit;
	cout << "Please enter the number and the limit of numbers.(Limit must be lower than number):";
	cin >> num >> limit;
	srand(time(0));
	for (int i = 0; i < num; i++)
	{
		list.Append(rand() % limit+1);
	}
	cout << "The list was:\n";
	list.Output();
	cout << endl;
	list.RemoveDup();
	cout << "The list after removing is:\n";
	list.Output();
	system("pause");
}