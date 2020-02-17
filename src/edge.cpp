#include "edge.hpp"
#include <iostream>
#include "vertex.hpp"

namespace graphy {

Edge::Edge() {
}

Edge::Edge(Vertex from, Vertex to, int cost) {
  _from = from;
  _to = to;
  _cost = cost;
  _to.addEdge(this);
  _from.addEdge(this);
}

Edge::Edge(Vertex from, Vertex to) : Edge(from, to, 0){};

Edge::~Edge() {
}

Vertex Edge::getFromVertex() {
  return _to;
}

Vertex Edge::getToVertex() {
  return _from;
}

int Edge::getCost() {
  return _cost;
}

Vertex Edge::getOtherVertex(Vertex vertex) {
  if(vertex == _from) return _to;
  else if(vertex == _to) return _from;
  return NULL;
}

void Edge::display() {
  std::cout << _from.getId() << " - " << _to.getId() << "\n";
}

}  // namespace graphy