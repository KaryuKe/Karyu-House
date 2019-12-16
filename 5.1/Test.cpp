#include<iostream>
#include"Graph.h"
#include<fstream>
#include"Graphmtx.h"
#include<string>
#include"Kruskal.h"
#include"DFSBFS.h"
using namespace std;
int main() {
	string a, b;
	/*cout << "Please enter the path of the file of edge."<<endl;
	cin >> a;
	cout << "Please enter the path of the file of vertex." << endl;
	cin >> b;*/
	a = "Edge.txt";
	b = "Vertex.txt";
	Graphmtx<char, int> testGraph(a,b);
	cout << "实验任务1：" << endl;
	cout << testGraph;
	char * vertice = testGraph.VerticesList;
	cout << "实验任务2：" << endl;
	for (int i = 0; i < 6; i++)
		{
			cout << "起始点为" << vertice[i] << endl;
			cout << "深度遍历：";
			DFS(testGraph, vertice[i]);
			cout << endl;
			cout << "广度遍历：";
			BFS(testGraph, vertice[i]);
			cout << endl;
		}
	MinSpanTree<char, int> tree(6);
	Kruskal(testGraph, tree);
	system("pause");
}