#pragma once
#include <vector>
#include <list>
#include <queue>

#include "Pipe.h"
#include "GameObject.h"
#include "VertexObject.h"
#include "Edge.h"
#include "Tap.h"
#include "Sink.h"

template <class T> class Edge;
template <class T> class VertexObject;

template <class T>
class Graph {
public:
	~Graph() = default;
	bool addVertex(const T& in);
	bool addEdge(const T& sourc, const T& dest, double w);
	std::vector<T> bfs(VertexObject<T>* v) const;
	std::vector<VertexObject<T>* > getVertexSet() const;
	void isBfsFoundSink();
	void graphReset();

private:
	std::vector<VertexObject<T>*> m_vertexSet;

};
//-----------------------------------------------------------------------------
template <class T>
std::vector<VertexObject<T>* > Graph<T>::getVertexSet() const {
	return m_vertexSet;
}
//-----------------------------------------------------------------------------
template <class T>
bool Graph<T>::addVertex(const T& in) {
	typename std::vector<VertexObject<T>*>::iterator it = m_vertexSet.begin();
	typename std::vector<VertexObject<T>*>::iterator ite = m_vertexSet.end();
	for (; it != ite; it++)
		if ((*it)->info == in) return false;
	VertexObject<T>* v1 = new VertexObject<T>(in);
	m_vertexSet.push_back(v1);

	return true;
}
//-----------------------------------------------------------------------------
template <class T>
bool Graph<T>::addEdge(const T& sourc, const T& dest, double w) {
	typename std::vector<VertexObject<T>*>::iterator it = m_vertexSet.begin();
	typename std::vector<VertexObject<T>*>::iterator ite = m_vertexSet.end();
	int found = 0;
	VertexObject<T>* edgeS= NULL, * edgeD= NULL;
	while (found != 2 && it != ite) {
		if ((*it)->info == sourc)
		{
			edgeS = *it; found++;
		}
		if ((*it)->info == dest)
		{
			edgeD = *it; found++;
		}
		it++;
	}
	if (found != 2) return false;
	edgeS->addEdge(edgeD, w);
	return true;
}
//-----------------------------------------------------------------------------
template <class T>
std::vector<T> Graph<T>::bfs(VertexObject<T>* v) const {
	std::vector<T> res;
	std::queue<VertexObject<T>*> q;
	q.push(v);
	v->visited = true;
	while (!q.empty()) {
		VertexObject<T>* v1 = q.front();
		q.pop();
		res.push_back(v1->info);
		typename std::vector<Edge<T> >::iterator it = v1->adj.begin();
		typename std::vector<Edge<T> >::iterator ite = v1->adj.end();
		for (; it != ite; it++) {
			VertexObject<T>* d = it->dest;
			if (d->visited == false) {
				d->visited = true;
				q.push(d);
			}
		}
	}
	return res;
}
//-----------------------------------------------------------------------------
template <class T>
void Graph<T>::isBfsFoundSink()
{
	bool isFlow = false;
	for (int i = 0 ; i < m_vertexSet.size(); i++)
	{
		auto res = bfs(m_vertexSet[i]);

		bool isSink = false;
		bool isTap = false;

		for (int j = 0 ; j < res.size(); j++)
		{
			if (typeid(*res[j]) == typeid(Sink))
				isSink = true;
			if (typeid(*res[j]) == typeid(Tap))
				isTap = true;

			if (isSink && isTap) {
				for (int x = 0; x < res.size(); x++)
					res[x]->printFlow();
				isFlow = true;
				
			}
			
		}
		if (!isFlow)
		{
			for (int x = 0; x < res.size(); x++)
				res[x]->printNoflow();
		}
	}
}
//-----------------------------------------------------------------------------
template <class T>
void Graph<T>::graphReset()
{
	m_vertexSet.clear();
}
