#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
class LinkNode {
public:
	int data;
	LinkNode *link;
	LinkNode(int value) :data(value), link(NULL)
	{
	}
	LinkNode() :link(NULL)
	{
	}
};

class List {
public:
	bool Remove(LinkNode *current);//删除当前项
	void Output();//输出
	void Append(int x);//向后追加项
	bool RemoveDup();//去重
	int Length() {
		LinkNode *p = first->link;
		int count = 0;
		while (p != NULL)									
		{
			p = p->link;
			count++;
		}

		return count;
	};//获取链表长度
	List() :first(NULL) {};
private:
	LinkNode *first;
};

bool List::Remove(LinkNode *current)
{
	LinkNode *temp = first;
	if (current != NULL)
	{
		while (temp->link != current)
			temp = temp->link;

		temp->link = current->link;
		current = temp;
		return true;
	}
	else
		return false;
}
bool List::RemoveDup()
{
		int * Q = new int[Length() + 1];//建立大小为n+1的数组
		for (int i = 0; i < Length() + 1; i++)
			Q[i] = 0;//将Q[i]都初始化为0
		LinkNode *current = first;
		if (current == NULL)//判断是否为空数组
			return false;
		int i = 0;
		while (current != NULL)
		{
			if (Q[current->data] == 1)
			{
				Remove(current);//有重复项时删除
			}
			else
			{
				Q[current->data] = 1;
			}
			current = current->link;//下一项
		}
		return true;
}
void List::Append(int a)
{
		LinkNode * temp;
		temp = new LinkNode(a);
		temp->link = first;
		first = temp;
}
void List::Output()
{
	if (first == NULL)
		cout << "Error:Empty List" << endl;
	else
	{
		LinkNode *current = first;
		while (current != NULL)
		{
			cout <<current->data << "  ";
			current = current->link;
		}
	}
}

