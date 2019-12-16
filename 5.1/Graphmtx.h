#pragma once
#include"Graph.h"
#include<iostream>
#define MaxWeight 0x7fffffff
#include<fstream>
#include<string>
using namespace std;
template<class T,class E>
class Graphmtx  {
	const E maxWeight = MaxWeight;
	friend istream& operator>>(istream& in, Graphmtx<T, E>& G) {
		int i, j, k, n, m;
		T e1, e2;
		E weight;
		in >> n >> m;
		for (i = 0; i < n; i++) {
			in >> e1; G.insertVertex(e1);
		}
		i = 0;
		while (i < m) {
			in >> e1 >> e2 >> weight;
			j = G.getVertexPos(e1); k = G.getVertexPos(e2);
			if (j == -1 || k == -1)
				cout << "边两端点信息有误，重新输入!" << endl;
			else {
				G.insertEdge(j, k, weight); i++;
			}
		}
		return in;
	}
	friend ostream& operator<<(ostream& out, Graphmtx<T, E>& G) {
		int i, j, n, m; T e1, e2; E w;
		n = G.NumberOfVertices(); m = G.NumberOfEdges();
		out << n << "," << m << endl;
		for(i=0;i<n;i++)
			for (j = i + 1; j < n; j++) {
				w = G.getWeight(i, j);
				if (w > 0 && w < MaxWeight) {
					e1 = G.getValue(i); e2 = G.getValue(j);
					out << "(" << e1 << "," << e2 << "," << w << ")" << endl;
				}
			}
		return out;
	}
public:
	Graphmtx(int sz = DefaultVertices) 
	{
		maxVertices = sz; numVertices = 0; numEdges = 0;
		int i, j;
		VerticesList = new T[maxVertices];		//构造顶点表数组
		Edge = (E**)new E*[maxVertices];		//创建邻接矩阵数组
		for (i = 0; i < maxVertices; i++)
			Edge[i] = new E[maxVertices];
		for (i = 0; i < maxVertices; i++)		//邻接矩阵初始化
			for (j = 0; j < maxVertices; j++)
				Edge[i][j] = (i == j) ? 0 : maxWeight;
	}
	~Graphmtx() { delete[]VerticesList; delete[]Edge; }
	Graphmtx(string edgeFile,string vertexFile) {
		maxVertices = DefaultVertices; numVertices = 0; numEdges = 0;
		int i, j;
		VerticesList = new T[maxVertices];		//构造顶点表数组
		Edge = (E**)new E*[maxVertices];		//创建邻接矩阵数组
		for (i = 0; i < maxVertices; i++)
			Edge[i] = new E[maxVertices];
		for (i = 0; i < maxVertices; i++)		//邻接矩阵初始化
			for (j = 0; j < maxVertices; j++)
				Edge[i][j] = (i == j) ? 0 : maxWeight;
		ifstream inputFile(vertexFile, ios::in);
		if (!inputFile)
		{
			cerr << "Failed to open the file of vertex!" << endl;
			exit(1);
		}
		int numofVertex,numofEdge,k;
		T e1,e2;
		E weight;
		inputFile >> numofVertex;
		for (i = 0; i < numofVertex; i++) {
			inputFile >> e1; insertVertex(e1);
		}
		ifstream inputFile2(edgeFile, ios::in);
		if (!inputFile2)
		{
			cerr << "Failed to open the file of edge!" << endl;
			exit(1);
		}
		inputFile2 >> numofEdge;
		i = 0;
		while (i < numofEdge) {
			inputFile2 >> e1 >> e2 >> weight;
			j = getVertexPos(e1); k = getVertexPos(e2);
			if (j == -1 || k == -1)
				cout << "边两端点信息有误!" << endl;
			else {
				insertEdge(j, k, weight); i++;
			}
		}
	}
	T getValue(int i)
	{
		return i >= 0 && i <= numVertices ? VerticesList[i] : NULL;
	}
	E getWeight(int v1, int v2)
	{
		return v1 != -1 && v2 != -1 ? Edge[v1][v2] : 0;
	}
	int getFirstNeighbor(int v) {
		if (v != -1) {
			for (int col = 0; col < numVertices; col++)
				if (Edge[v][col] > 0 && Edge[v][col] < maxWeight)return col;
		}
		return -1;
	}
	int getNextNeighbor(int v, int w) {
		if (v != -1 && w != -1) {
			for (int col = w + 1; col < maxVertices; col++)
				if (Edge[v][col] > 0 && Edge[v][col] < maxWeight)return col;
		}
		return -1;
	}
	bool insertVertex(const T& vertex) {
		if (numVertices == maxVertices)return false;
		VerticesList[numVertices++] = vertex;
		return true;
	}
	bool insertEdge(int v1, int v2, E cost) {
		if (v1 > -1 && v1<numVertices&&v2>-1 && v2 < numVertices&&Edge[v1][v2] == MaxWeight)
		{
			Edge[v1][v2] = Edge[v2][v1] = cost; numEdges++; return true;
		}
		else return false;
	}
	bool removeVertex(int v) {
		if (v < 0 || v >= numVertices)return false;
		if (numVertices == 1)return false;
		int i, j;
		VerticesList[v] = VerticesList[numVertices - 1];
		for (i = 0; i < numVertices; i++)
			if (Edge[i][v] > 0 && Edge[i][v] < maxWeight)numEdges--;
		for (i = 0; i < numVertices; i++)
			Edge[i][v] = Edge[i][numVertices - 1];
		numVertices--;
		for (j = 0; j < numVertices; j++)
			Edge[v][j] = Edge[numVertices][j];
		return true;
	}
	bool removeEdge(int v1, int v2) {
		if (v1 > -1 && v1<numVertices&&v2>-1 && v2 < numVertices&&Edge[v1][v2]>0 && Edge[v1][v2] < maxWeight) {
			Edge[v1][v2] = Edge[v2][v1] = maxWeight;
			numEdges--;
			return true;
		}
		else return false;
	}
	bool GraphEmpty()const {
		if (numEdges == 0)return true;
		else return false;
	}
	bool GraphFull() {
		if (numVertices == maxVertices || numEdges == maxVertices * (maxVertices - 1) / 2)return true;
		else return false;
	}
	int NumberOfVertices() { return numVertices; }
	int NumberOfEdges() { return numEdges; }
//private:
	T * VerticesList;
	E * *Edge;
	int maxVertices;
	int numEdges;
	int numVertices;
	int getVertexPos(T Vertex) {
		for (int i = 0; i < numVertices; i++)
			if (VerticesList[i] == Vertex)return i;
		return -1;
	}
};