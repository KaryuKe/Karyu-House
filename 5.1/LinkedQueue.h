#include<iostream>
template<class T>
struct LinkNode
{
	T data;
	LinkNode<T> * link;
	LinkNode(LinkNode<T> * ptr = NULL)
	{
		link = ptr;
	}
	LinkNode(const T& item)
	{
		data = item;
		link = NULL;
	}
};
template<class T>
class LinkedQueue
{
public:
	LinkedQueue() :rear(NULL), front(NULL) {}
	~LinkedQueue()
	{
		makeEmpty();
	}
	bool DeleteLinkNode(int t)
	{
		LinkNode<T>* p;
		LinkNode<T>* p2;
		p = getLinkNode(t);
		if (t == 1)
		{
			front = p->link;
			delete p;
			return true;
		}
		p2 = getLinkNode(t - 1);

		if (t == getSize())
		{
			p2->link = NULL;
			delete p;
			return true;
		}
		if (t > 1 && t < getSize())
		{
			p2->link = p->link;
			delete p;
			return true;
		}
		return false;
	}
	bool IsEmpty()const
	{
		return (front == NULL) ? true : false;
	}
	bool EnQueue(T & x)
	{
		if (front == NULL)
		{
			LinkNode<T> * l = new LinkNode<T>(x);
			front = rear = l;

			if (front == NULL)
				return false;
		}
		else
		{
			rear->link = new LinkNode<T>(x);

			if (rear->link == NULL)
				return false;
			rear = rear->link;
		}

		return true;
	}
	bool DeQueue(T& x)
	{
		if (IsEmpty() == true)
			return false;
		LinkNode<T> * p = front;
		x = front->data;
		front = front->link;
		delete p;
		return true;
	}
	bool getFront(T& x)const
	{
		if (IsEmpty() == true)
			return false;
		x = front->data;
		return true;
	}
	void makeEmpty()
	{
		LinkNode<T> * p;
		while (front != NULL)
		{
			p = front;
			front = front->link;
			delete p;
		}
	}
	void Insert(int t, T& x)
	{
		LinkNode<T> * ptrNode = new LinkNode<T>(x);
		LinkNode<T>* p;
		if (t == 1)
		{
			ptrNode->link = front;
			front = ptrNode;
		}
		else
		{
			p = getLinkNode(t - 1);
			if (t == getSize())
			{
				ptrNode->link = p->link;
				p->link = ptrNode;
				rear = ptrNode;
			}
			else
			{
				ptrNode->link = p->link;
				p->link = ptrNode;
			}
		}
	}
	void output()
	{
		LinkNode<T> * p = front;
		while (p != NULL)
		{
			cout << p->data << endl;
			p = p->link;
		}
	}
	int getSize()const
	{
		LinkNode<T> * p = front;
		int k = 0;
		while (p != NULL)
		{
			p = p->link; k++;
		}
		return k;
	}
	LinkNode<T>* getMinData2Ptr()
	{
		LinkNode<T>* p;
		LinkNode<T>* p2;
		p = getFrontPtr();
		for (int i = 2; i <= getSize(); i++)
		{
			p2 = getLinkNode(i);
			if (p2->data2 < p->data2)
				p = p2;
		}
		return p;
	}
	LinkNode<T>* getFrontPtr()
	{
		return front;
	}
	LinkNode<T>* getLinkNode(int t)
	{
		if (t == 0)
			cout << "error" << endl;
		if (front == NULL)
			return front;
		LinkNode<T>* p = NULL;
		p = front;
		int i = 1;
		while (i < t)
		{
			p = p->link;
			i++;
		}
		return p;
	}
	protected:
		LinkNode<T> * front, *rear;
};
