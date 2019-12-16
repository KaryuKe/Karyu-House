#include<iostream>
using namespace std;

class UFSets
{
public:
	UFSets(int sz)
	{
		size = sz;
		parent = new int[size];
		for (int i = 0; i < size; i++)
			parent[i] = -1;
	}
	~UFSets()
	{
		delete[]parent;
	}
	UFSets& operator=(UFSets& R)
	{
		size = R.size;
		for (int i = 0; i < size; i++)
			parent[i] = R.parent[i];
		return R;
	}
	void Union(int Root1, int Root2)
	{
		parent[Root1] += parent[Root2];
		parent[Root2] = Root1;
	}
	int Find(int x)
	{
		if (parent[x] < 0)return x;
		else return Find(parent[x]);
	}
	void WeightedUnion(int Root1, int Root2)
	{
		int r1 = Find(Root1);
		int r2 = Find(Root2);
		int temp;
		if (r1 != r2)
		{
			temp = parent[r1] + parent[r2];
		}
		if (parent[r2] < parent[r1])
		{
			parent[r1] = r2;
			parent[r2] = temp;
		}
		else
		{
			parent[r2] = r1;
			parent[r1] = temp;
		}
	}
	void output()
	{
		for (int i = 0; i < size; i++)
			cout << parent[i] << " ";
		cout << endl;
	}
private:
	int * parent;
	int size;
}; 
