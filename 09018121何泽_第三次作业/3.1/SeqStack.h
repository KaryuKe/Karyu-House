#pragma once
#include<assert.h>
#include<iostream>
#include"Stack.h"
using namespace std;
const int stackIncrement = 20;
template<class T>
class SeqStack :public Stack<T> {
public:
	SeqStack(int sz = 50) :topn(-1), maxSize(sz){
		elements = new T[maxSize];
		assert(elements != NULL);
	}
	~SeqStack() { delete[]elements; }
	void Push(const T& x) {
		if (IsFull() == true)overflowProcess();
		elements[++topn] = x;
	}
	bool Pop(T& x) {
		if (IsEmpty() == true)return false;
		x = elements[topn--];
		return true;
	}
	bool getTop(T& x)const {
		if (IsEmpty() == true)return false;
		x = elements[topn];
		return true;
	}
	T top() {
		if (IsEmpty() == false)
			return elements[topn];
		else
			return -1;
	}
	bool IsEmpty()const { return(topn == -1) ? true : false; }
	bool IsFull()const { return (topn == maxSize - 1) ? true : false; }
	int getSize()const { return topn + 1; }
	void MakeEmpty() { topn = -1; }
	friend ostream& operator<<(ostream& os, SeqStack<T>&s);
private:
	T * elements;
	int topn;
	int maxSize;
	void overflowProcess() {
		T* newArray = new T[maxSize + stackIncrement];
		if (newArray == NULL) { cerr << "´æ´¢·ÖÅäÊ§°Ü£¡" << endl; exit(1); }
		for (int i = 0; i <= topn; i++)newArray[i] = elements[i];
		maxSize = maxSize + stackIncrement;
		delete []elements;
		elements = newArray;
	}
};

template<class T>
ostream& operator<<(ostream& os, SeqStack<T>&s) {
	os << "top=" << s.top << endl;
	for (int i = 0; i <= s.top; i++)
		os << i << ":" << s.elements[i] << endl;
	return os;
}