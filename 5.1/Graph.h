#pragma once
#define MaxWeight 0x7fffffff
const int DefaultVertices = 30;
template<class T,class E>
class Graph {
public:
	const E maxWeight = MaxWeight;
	Graph(int sz = DefaultVertices);
	~Graph();
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
	virtual T getValue(int i);
	virtual E getWeight(int v1, int v2);
	virtual int getFirstNeighbor(int v);
	virtual int getNextNeightbor(int v, int w);
	virtual bool insertVertex(const T& vertex);
	virtual bool insertEdge(int v1, int v2, E cost);
	virtual bool removeVertex(int v);
	virtual bool removeEdge(int v1, int v2);
//protected:
	int maxVertices;
	int numEdges;
	int numVertices;
	virtual int getVertexPos(T vertex);
};