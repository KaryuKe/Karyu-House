#pragma once
#include<string>
using namespace std;
class GradeBook
{
public:
	GradeBook(string, string);
	void setCourseName(string);
	void setInstructorName(string);
	string getCourseName();
	string getInstructorName();
	void displayMessage();
private:
	string courseName;
	string instructorName;
};
