#include <iostream>
#include <cstring>
#include "pch.h"
using namespace std;
int main()
{
	int n1, n2;
	string nb;
	{
		cout << "请输入②个数字！\n";
		cin >> n1 >> n2;
		if (n1 == n2)
			cout << n1 << "=" << n2 << endl;
		else cout << n1 << "≠" << n2 << endl;
		if (n1 < n2)
			cout << n1 << "＜" << n2 << endl;
		else cout << n1 << "≥" << n2 << endl;
		if (n1 > n2)
			cout << n1 << "＞" << n2 << endl;
		else cout << n1 << "≤" << n2 << endl;
		cout << "谁是东大最牛逼的人？\n";
		cin >> nb;
		if (nb == "陈曦")
			do {
				cout << nb << "牛逼！太强了！";
			} while (nb != "陈曦");
		else
			do {
				cout << nb << "不如陈曦牛逼！太辣鸡了！";
			} while (nb != "陈曦");
	}
}