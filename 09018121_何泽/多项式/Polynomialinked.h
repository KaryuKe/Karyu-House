//单链表形式，参照书中2.5建立，多项式按升序排列，最后一项为指数最大者
#pragma once
#include<iostream>
using namespace std;
struct Term {	//多项式节点的定义
	float coef;	//系数
	int exp;	//指数
	Term * link;
	Term(float c, int e, Term * next = NULL)
	{
		coef = c; exp = e; link = next;
	}
	Term * InsertAfter(float c, int e);
	friend ostream& operator<<(ostream&, const Term&);
};

class Polynomial {								//多项式类的定义
public:
	Polynomial() { first = new Term(0, -1); }	//构造函数，建立空链表
	Polynomial(Polynomial& R);					//复制构造函数
	int maxOrder();								//计算最大阶数
	float Calc(float x);						//增加的成员函数，返回计算出的多项式值
	Term *getHead()const { return first; }		//获得表头指针
private:
	Term * first;
	float ValueofTerm(Term *p, float x);
	friend ostream& operator<<(ostream&, const Polynomial&);
	friend istream& operator>>(istream&, Polynomial&);
	//friend Polynomial operator+(Polynomial&, Polynomial&);
	//friend Polynomial operator*(Polynomial&, Polynomial&);
};

float Polynomial::ValueofTerm(Term *p, float x) {
	//递归计算，使用2.27中所说的Pn（x)=xPn-1(x)+an
	if (p->link == NULL)return p->coef;
	else return p->coef + x * ValueofTerm(p->link, x);
};

float Polynomial::Calc(float x) {
	//计算多项式
	Term * p = first->link;
	if (p == first)return 0;//判断是否为空
	else return ValueofTerm(p, x);
};

Term * Term::InsertAfter(float c, int e) {
	//在当前由this指针指示的项（即调用此函数的对象）后面插入一个新项。
	link = new Term(c, e, link);
	return link;
};

ostream& operator<<(ostream& out, const Term& x) {
	//输出一个项x的内容到输出流out中
	if (x.coef == 0.0)return out;
	out << x.coef;
	switch (x.exp) {
	case 0:break;
	case 1:out << "X"; break;
	default:out << "X^" << x.exp; break;
	}
	return out;
};

Polynomial::Polynomial(Polynomial& R) {
	//复制构造函数
	first = new Term(0, -1);
	Term * destptr = first, *srcptr = R.getHead()->link;
	while (srcptr != NULL) {
		destptr->InsertAfter(srcptr->coef, srcptr->exp);
		srcptr = srcptr->link;
		destptr = destptr->link;
	}
};

int Polynomial::maxOrder() {
	//计算最大阶数，即最后一项的阶数
	Term * current = first;
	while (current->link != NULL)current = current->link;
	return current->exp;
};

istream& operator>>(istream& in, Polynomial& x) {
	//从输入流in输入各项，用尾插法建立一个多项式
	Term * rear = x.getHead(); //尾指针
	int c, e;
	while (1) {
		cout << "Input a term(coef,exp):" << endl;
		in >> c >> e;//输入项的系数c和指数e
		if (e < 0)break;//用e<0控制输入结束
		rear = rear->InsertAfter(c, e);//链接到rear所指结点后
	}
	return in;
};

ostream& operator<<(ostream& out, Polynomial& x) {
	//输出带附加头结点的多项式链表x
	Term * current = x.getHead()->link;
	cout << "The polynomial is:" << endl;
	bool h = true;
	while (current != NULL) {
		if (h == false && current->coef > 0.0)out << "+";
		h = false;
		out << *current;//调用Term类的重载操作“<<”
		current = current->link;
	}
	out << endl;
	return out;
};

