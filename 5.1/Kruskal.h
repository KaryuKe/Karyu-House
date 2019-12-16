#define MaxValue 0x7fffffff
#include<iostream>
#include"Graph.h"
#include"LinkedQueue.h"
#include"MinHeap.h"
#include"UFSets.h"
#include"MinSpanTree.h"
using namespace std;
template<class T, class E>
void Kruskal(Graphmtx<T, E>& G, MinSpanTree<T, E>& MST)
{
	MSTEdgeNode<T, E>edge;
	int u, v, count=1;
	int size;
	int n = G.NumberOfVertices();
	int m = G.NumberOfEdges();	
	UFSets Set(n);
	MinHeap<MSTEdgeNode<T, E>>Minheap(m);

	cout << "当前并查集：";
	Set.output();
	for (u = 0; u < n; u++)
		for (v = u + 1; v < n; v++)
			if (G.getWeight(u, v) != maxValue)
			{
				edge.tail = u;
				edge.head = v;
				edge.key = G.getWeight(u, v);
				Minheap.Insert(edge);
				size = Minheap.getCurrentSize();
				cout << "当前最小堆:" << endl;
				for (int i = 0; i < size; i++)
					cout << "(" << G.getValue(Minheap.getHeapValue(i).head) << ","
					<< G.getValue(Minheap.getHeapValue(i).tail)
					<< "," << Minheap.getHeapValue(i).key << ")" << endl;
				cout << endl;
			}
	while (count < n)
	{
		Minheap.RemoveMin(edge);
		u = Set.Find(edge.tail);
		v = Set.Find(edge.head);
		if (u != v)
		{
			Set.Union(u, v);
			MST.Insert(edge);
			count++;
			int n2 = MST.getSize();
			cout << endl;

			cout << "当前最小生成树：" << endl;
			for (int i = 0; i < n2; i++)
				cout << "(" << G.getValue(MST.getHeadValue(i)) << ","
				<< G.getValue(MST.getTailValue(i)) << ","
				<< MST.getKeyValue(i) << ")" << endl;
			cout << endl;
			cout << "当前并查集："; Set.output();
			cout << endl;

		}

		size = Minheap.getCurrentSize();
		cout << "当前最小堆:" << endl;
		for (int i = 0; i < size; i++)
			cout << "(" << G.getValue(Minheap.getHeapValue(i).head) << ","
			<< G.getValue(Minheap.getHeapValue(i).tail)
			<< "," << Minheap.getHeapValue(i).key << ")" << endl;
		cout << endl;
	}

}
