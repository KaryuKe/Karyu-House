//��������ʽ����������2.5����������ʽ���������У����һ��Ϊָ�������
#pragma once
#include<iostream>
using namespace std;
struct Term {	//����ʽ�ڵ�Ķ���
	float coef;	//ϵ��
	int exp;	//ָ��
	Term * link;
	Term(float c, int e, Term * next = NULL)
	{
		coef = c; exp = e; link = next;
	}
	Term * InsertAfter(float c, int e);
	friend ostream& operator<<(ostream&, const Term&);
};

class Polynomial {								//����ʽ��Ķ���
public:
	Polynomial() { first = new Term(0, -1); }	//���캯��������������
	Polynomial(Polynomial& R);					//���ƹ��캯��
	int maxOrder();								//����������
	float Calc(float x);						//���ӵĳ�Ա���������ؼ�����Ķ���ʽֵ
	Term *getHead()const { return first; }		//��ñ�ͷָ��
private:
	Term * first;
	float ValueofTerm(Term *p, float x);
	friend ostream& operator<<(ostream&, const Polynomial&);
	friend istream& operator>>(istream&, Polynomial&);
	//friend Polynomial operator+(Polynomial&, Polynomial&);
	//friend Polynomial operator*(Polynomial&, Polynomial&);
};

float Polynomial::ValueofTerm(Term *p, float x) {
	//�ݹ���㣬ʹ��2.27����˵��Pn��x)=xPn-1(x)+an
	if (p->link == NULL)return p->coef;
	else return p->coef + x * ValueofTerm(p->link, x);
};

float Polynomial::Calc(float x) {
	//�������ʽ
	Term * p = first->link;
	if (p == first)return 0;//�ж��Ƿ�Ϊ��
	else return ValueofTerm(p, x);
};

Term * Term::InsertAfter(float c, int e) {
	//�ڵ�ǰ��thisָ��ָʾ��������ô˺����Ķ��󣩺������һ�����
	link = new Term(c, e, link);
	return link;
};

ostream& operator<<(ostream& out, const Term& x) {
	//���һ����x�����ݵ������out��
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
	//���ƹ��캯��
	first = new Term(0, -1);
	Term * destptr = first, *srcptr = R.getHead()->link;
	while (srcptr != NULL) {
		destptr->InsertAfter(srcptr->coef, srcptr->exp);
		srcptr = srcptr->link;
		destptr = destptr->link;
	}
};

int Polynomial::maxOrder() {
	//�����������������һ��Ľ���
	Term * current = first;
	while (current->link != NULL)current = current->link;
	return current->exp;
};

istream& operator>>(istream& in, Polynomial& x) {
	//��������in��������β�巨����һ������ʽ
	Term * rear = x.getHead(); //βָ��
	int c, e;
	while (1) {
		cout << "Input a term(coef,exp):" << endl;
		in >> c >> e;//�������ϵ��c��ָ��e
		if (e < 0)break;//��e<0�����������
		rear = rear->InsertAfter(c, e);//���ӵ�rear��ָ����
	}
	return in;
};

ostream& operator<<(ostream& out, Polynomial& x) {
	//���������ͷ���Ķ���ʽ����x
	Term * current = x.getHead()->link;
	cout << "The polynomial is:" << endl;
	bool h = true;
	while (current != NULL) {
		if (h == false && current->coef > 0.0)out << "+";
		h = false;
		out << *current;//����Term������ز�����<<��
		current = current->link;
	}
	out << endl;
	return out;
};

