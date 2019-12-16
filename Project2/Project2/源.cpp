#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double x, accuracy, counter = 1, plus, n, m = 1, end = 1;
	cout << "Please input x" << endl;
	cin >> x;
	cout << "Please input the accuracy." << endl;
	cin >> accuracy;
	while (plus >= accuracy)
	{
		n = pow(x, counter);
		m = counter * m;
		plus = n / m;
		end = end + plus;
		counter++;
	}
	cout << "The value of e^x is " << end << endl;
}