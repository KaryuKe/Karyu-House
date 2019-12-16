#include<iostream>
#include "GB.h"
using namespace std;
int main()
{
	GradeBook gb1("CS101 Introduction to C++ Programming", "Sam Smith");
	gb1.displayMessage();
	cout << "Changing instructor name to Judy Jones" << endl;
	gb1.setInstructorName("Judy Jones");
	gb1.displayMessage();
	system("pause");
}