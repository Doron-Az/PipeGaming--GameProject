#pragma once
#include <vector>

template <class T> class Graph;
template <class T> class Edge;

template <class T>
class VertexObject {

public:
	VertexObject(T in);
	VertexObject(const VertexObject<T>& v);
	T getInfo() const;
	int getNum() { return num; }
	friend class Graph<T>;

private:
	T info;
	std::vector<Edge<T> > adj;
	bool visited;
	int num;
	int low;
	VertexObject<T>* path;
	void addEdge(VertexObject<T>* dest, double w);
	bool removeEdgeTo(VertexObject<T>* d);
};
//----------------------------------------------------------------------------
template <class T>
T VertexObject<T>::getInfo() const {
	return info;
}//----------------------------------------------------------------------------
template <class T>
bool VertexObject<T>::removeEdgeTo(VertexObject<T>* d) {
	typename std::vector<Edge<T> >::iterator it = adj.begin();
	typename std::vector<Edge<T> >::iterator ite = adj.end();
	while (it != ite) {
		if (it->dest == d) {
			adj.erase(it);
			return true;
		}
		else it++;
	}
	return false;
}
//----------------------------------------------------------------------------
template <class T>
VertexObject<T>::VertexObject(T in) : info(in), visited(false), num(0), low(0), path(NULL) {}
//----------------------------------------------------------------------------
template <class T>
VertexObject<T>::VertexObject(const VertexObject<T>& in) : info(in.info), visited(in.visited), num(in.num), low(in.low), path(NULL) {}
//----------------------------------------------------------------------------
template <class T>
void VertexObject<T>::addEdge(VertexObject<T>* dest, double w) {
	Edge<T> edgeD(dest, w);
	adj.push_back(edgeD);
}
//----------------------------------------------------------------------------
