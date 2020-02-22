#include "vertex.hpp"
#include <iostream>
#include <vector>
#include "edge.hpp"

namespace graphy {

Vertex::Vertex() {
}

Vertex::Vertex(int id) {
  _id = id;
}

Vertex::~Vertex() {
}

void Vertex::addEdge(Edge* edge) {
  _edges.push_back(edge);
}

Edge Vertex::getEdge(Vertex vertex) {
  int targetId = vertex.getId();
  for (std::vector<Edge*>::iterator it = _edges.begin(); it != _edges.end(); ++it) {
    Edge edge = **it;
    int fromId = edge.getFromVertex()->getId();
    int toId = edge.getToVertex()->getId();
    if (targetId == fromId || targetId == toId) return edge;
  }
  return {};
}

std::vector<Edge*> Vertex::getEdges() {
  return _edges;
}

int Vertex::getId() const {
  return _id;
}

bool operator==(const Vertex& lhs, const Vertex& rhs) { return lhs.getId() == rhs.getId(); }
bool operator<(const Vertex& lhs, const Vertex& rhs) { return lhs.getId() < rhs.getId(); }

}  // namespace graphy