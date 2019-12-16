#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<cstdlib>
#include<sstream>
#include<math.h>
#include"SeqStack.h"
#include <algorithm>  
using namespace std;
string func;
bool read()
{
	string fucFile;
	cout << "Enter the file name:";
	cin >> fucFile;
	ifstream inputFile(fucFile, ios::in);
	if (!inputFile)
	{
		cerr << "Failed to open the file!" << endl;
		return 0;
	}
	char ch;
	ostringstream tmp;
	while (tmp&&inputFile.get(ch))
		tmp.put(ch);
	func = tmp.str();
	return 1;
}
int isp(char c) {
	if (c == '#')return 0;
	if (c == '(')return 1;
	if (c == '*' || c == '/' || c == '%')return 5;
	if (c == '+' || c == '-')return 3;
	if (c == ')')return 6;
}
int icp(char c) {
	if (c == '#')return 0;
	if (c == '(')return 6;
	if (c == '*' || c == '/' || c == '%')return 4;
	if (c == '+' || c == '-')return 2;
	if (c == ')')return 1;
}
void toPostfix(string func)
{
	int i = 0;
	int size = func.size();
	SeqStack<char> s;
	char ch = '#', ch1, op;
	s.Push(ch);
	ch = func[i++];
	while(s.IsEmpty()==false&&i<=size+1)
		if (isdigit(ch)) { cout << ch; ch = func[i++]; }
		else {
			s.getTop(ch1);
			if(isp(ch1)<icp(ch))
			{
				s.Push(ch); ch = func[i++];
			}
			else if (isp(ch1) > icp(ch))
			{
				s.Pop(op); cout << op;
			}
			else {
				s.Pop(op);
				if (op == '(')
					ch = func[i++];
			}
		}
}
int pri(char a) {
	switch (a) {
	case '+':
		return 1;
	case '-':
		return 1;
	case '*':
		return 2;
	case '/':
		return 2;
	}
}
void toPrefix(string func)
{
	SeqStack<char>S1, S2;
	char current;
	char tmp;
	for (int i = func.size(); i >= 0; i--) {
		current = func[i];
		if (current >= 'A' && current <= 'Z')
			S1.Push(current);
		else if (current == ')' || S2.IsEmpty() == 1 || S2.top() == ')') {
			S2.Push(current);
		}
		else if (current == '(') {
			while (S2.top() != ')') {
				S1.Push(S2.top());
				S2.Pop(tmp);
			}
			S2.Pop(tmp);
		}
		else {
			while (S2.IsEmpty() == 0 && pri(current) < pri(S2.top()) && S2.top() != ')') {
				S1.Push(S2.top());
				S2.Pop(tmp);
			}
			S2.Push(current);
		}
	}
	while (S2.IsEmpty() != 1) {
		S1.Push(S2.top());
		S2.Pop(tmp);
	}
	while (S1.IsEmpty() != 1) {
		cout << S1.top();
		S1.Pop(tmp);
	}
}
//尝试另一种方法，有错误
//void toPrefix(string func)
//{/*
//	reverse(func.begin(), func.end());
//	for (int k = 0; k < func.size(); k++)
//	{
//		if (func[k] == '(')func[k] = ')';
//		else if (func[k] == ')')func[k] = '(';
//	}
//	int i = 0;
//	int size = func.size();
//	SeqStack<char> s;
//	char ch = '#', ch1, op;
//	s.Push(ch);
//	ch = func[i++];
//	string result;
//	while (s.IsEmpty() == false && i <= size + 1)
//		if (isdigit(ch)) { result+= ch; ch = func[i++]; }
//		else {
//			s.getTop(ch1);
//			if (isp(ch1) < icp(ch))
//			{
//				s.Push(ch); ch = func[i++];
//			}
//			else if (isp(ch1) > icp(ch))
//			{
//				s.Pop(op); result += op;
//			}
//			else {
//				s.Pop(op);
//				if (op == '(')
//					ch = func[i++];
//			}
//		}
//	reverse(result.begin(), result.end());
//	cout << result;
//*/
//}
int main() {
	while (1) {
		if (read())
			break;
	}
	cout << "中缀表达式为： " << func;
	cout << "\n后缀表达式为： ";
	toPostfix(func);
	cout << "\n前缀表达式为：";
	toPrefix(func);
	system("pause");
}
