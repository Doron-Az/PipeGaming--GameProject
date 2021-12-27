#pragma once

template <class T> class VertexObject;

template <class T>
class Edge {

public:
	Edge(VertexObject<T>* d, double w);
	~Edge() = default;
	VertexObject<T>* getDest();
	friend class Graph<T>;

private:
	VertexObject<T>* dest;
	double weight;
	bool visited;
};
//-----------------------------------------------------------------------------
template <class T>
Edge<T>::Edge(VertexObject<T>* d, double w) : dest(d), weight(w), visited(false) {}
//-----------------------------------------------------------------------------
template<class T>
 VertexObject<T>* Edge<T>::getDest()
{
	return dest;
}
