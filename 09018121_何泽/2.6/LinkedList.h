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
	bool Remove(LinkNode *current);//ɾ����ǰ��
	void Output();//���
	void Append(int x);//���׷����
	bool RemoveDup();//ȥ��
	int Length() {
		LinkNode *p = first->link;
		int count = 0;
		while (p != NULL)									
		{
			p = p->link;
			count++;
		}

		return count;
	};//��ȡ������
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
		int * Q = new int[Length() + 1];//������СΪn+1������
		for (int i = 0; i < Length() + 1; i++)
			Q[i] = 0;//��Q[i]����ʼ��Ϊ0
		LinkNode *current = first;
		if (current == NULL)//�ж��Ƿ�Ϊ������
			return false;
		int i = 0;
		while (current != NULL)
		{
			if (Q[current->data] == 1)
			{
				Remove(current);//���ظ���ʱɾ��
			}
			else
			{
				Q[current->data] = 1;
			}
			current = current->link;//��һ��
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

