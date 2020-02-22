#ifdef __EMSCRIPTEN__
#include <emscripten/bind.h>
#endif
#include <iostream>
#include <vector>
#include "edge.hpp"
#include "graph.hpp"
#include "vertex.hpp"

namespace graphy {

#ifdef __EMSCRIPTEN__
using namespace emscripten;
#endif

Graph::Graph() {
  addVertex(0);
  _type = DIRECTED;
}

Graph::Graph(GraphType graphType) {
  _type = graphType;
}
Graph::~Graph() {}

GraphType Graph::getType() {
  return _type;
}

bool Graph::hasVertex(int id) {
  for (std::list<Vertex>::iterator it = _vertices.begin(); it != _vertices.end(); ++it) {
    Vertex vertex = *it;
    int currentId = vertex.getId();
    if (currentId == id) return true;
  }
  return false;
}

bool Graph::hasEdge(int fromVertexID, int toVertexID) {
  for (std::list<Edge>::iterator it = _edges.begin(); it != _edges.end(); ++it) {
    Edge edge = *it;
    int fromId = edge.getFromVertex()->getId();
    int toId = edge.getFromVertex()->getId();
    if (fromId == fromVertexID && toId == toVertexID) return true;
  }
  return false;
}

void Graph::addVertex(int id) {
  for (std::list<Vertex>::iterator it = _vertices.begin(); it != _vertices.end(); it++) {
    Vertex& vertex = *it;
    int currentId = vertex.getId();
    if (currentId == id) return;
  }
  _vertices.push_back(Vertex(id));
}

Vertex* Graph::getVertex(int id) {
  for (std::list<Vertex>::iterator it = _vertices.begin(); it != _vertices.end(); it++) {
    Vertex& vertex = *it;
    int currentId = vertex.getId();
    if (currentId == id) return &vertex;
  }
  return &_vertices.front();
}

void Graph::addEdge(int fromVertexID, int toVertexID) {
  if (hasEdge(fromVertexID, toVertexID)) return;

  addVertex(fromVertexID);
  addVertex(toVertexID);

  Vertex* fromVertex = getVertex(fromVertexID);
  Vertex* toVertex = getVertex(toVertexID);

  _edges.push_back(Edge(fromVertex, toVertex, _edges.size()));

  fromVertex->addEdge(&_edges.back());
  toVertex->addEdge(&_edges.back());

  // std::cout << &_edges.back() << "\n";
  // std::cout << _edges.back().getFromVertex()->getEdges().size() << "\n";
  // std::cout << fromVertex->getEdges().size() << "\n";
  // std::cout << _edges.back().getFromVertex()->getEdges().size() << "\n";
  // std::cout << "====\n";
}

std::list<graphy::Vertex> Graph::getVertices() {
  return _vertices;
}

std::list<graphy::Edge> Graph::getEdges() {
  return _edges;
}

void Graph::display() {
  for (std::list<Vertex>::iterator it = _vertices.begin(); it != _vertices.end(); it++) {
    Vertex vertex = *it;
    std::cout << vertex.getId() << ",";
  }
  std::cout << "\n";

  for (std::list<Edge>::iterator it = _edges.begin(); it != _edges.end(); it++) {
    Edge edge = *it;
    edge.display();
  }
  std::cout << "===========\n";
}

#ifdef __EMSCRIPTEN__
// Binding code
EMSCRIPTEN_BINDINGS(Graph) {
  class_<Graph>("Graph")
      .constructor<>()
      .function("display", &Graph::display)
      .function("addEdge", &Graph::addEdge)
      .function("addVertex", &Graph::addVertex)
      .function("hasEdge", &Graph::hasEdge);
}
#endif

};  // namespace graphy
