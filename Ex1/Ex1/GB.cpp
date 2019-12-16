#include <iostream>
#include "GB.h"
using namespace std;
GradeBook::GradeBook(string name1, string name2)
{
	setCourseName(name1);
	setInstructorName(name2);
}
void GradeBook::setCourseName(string name1)
{
	courseName = name1;
}
void GradeBook::setInstructorName(string name2)
{
	instructorName = name2;
}
string GradeBook::getCourseName()
{
	return courseName;
}
string GradeBook::getInstructorName()
{
	return instructorName;
}
void GradeBook::displayMessage()
{
	cout << "Welcome to the grade book for\n" <<getCourseName() <<"!"<< "\nThis course is presented by " << getInstructorName() << endl;
}