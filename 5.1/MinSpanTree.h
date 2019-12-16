#define maxValue 0x7fffffff
template<class T, class E>
struct MSTEdgeNode
{
	int tail, head;
	E key;
	MSTEdgeNode() :tail(-1), head(-1), key(0) {}
	bool operator<=(MSTEdgeNode<T, E>& R)
	{
		return key <= R.key;
	}
	bool operator>(MSTEdgeNode<T, E>& R)
	{
		return key > R.key;
	}
};
template<class T, class E>
class MinSpanTree
{
protected:
	MSTEdgeNode<T, E>* edgevalue;
	int MaxSize, n;
public:
	MinSpanTree(int sz) :MaxSize(sz), n(0)
	{
		edgevalue = new MSTEdgeNode<T, E>[sz];
	}
	int Insert(MSTEdgeNode<T, E>& item)
	{
		edgevalue[n].head = item.head;
		edgevalue[n].tail = item.tail;
		edgevalue[n].key = item.key;
		n++;
		return n;
	}
	int getSize()
	{
		return n;
	}
	int getHeadValue(int i)
	{
		return edgevalue[i].head;
	}
	int getTailValue(int i)
	{
		return edgevalue[i].tail;
	}
	E getKeyValue(int i)
	{
		return edgevalue[i].key;
	}
	void output()
	{
		cout << endl;
		cout << "最小生成树为：" << endl;
		for (int i = 0; i < n; i++)
			cout << "(" << edgevalue[i].head << "," << edgevalue[i].tail << "," << edgevalue[i].key << ")" << endl;
	}

};