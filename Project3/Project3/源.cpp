#include<iostream>
using namespace std;
int main()
{
	int n,n1,n2,n3,n4;
	cout << "Input the number you want to encrypt." << endl;
	cin >> n;
	n1 = n / 1000;
	n2 = n % 1000 / 100;
	n3 = n % 100 / 10;
	n4 = n % 10;
	n1 = (n1 + 7) % 10;
	n2 = (n2 + 7) % 10;
	n3 = (n3 + 7) % 10;
	n4 = (n4 + 7) % 10;
	n = n3 * 1000 + n1 * 10 + n2 + n4 * 100;
	cout << "The encrypted number is "<<n << endl;
}