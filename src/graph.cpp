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
  return false;
}

bool Graph::hasEdge(int fromVertexID, int toVertexID) {
  return false;
}

void Graph::addVertex(int id) {
  if (this->hasVertex(id)) return;

  Vertex vertex = Vertex(id);
  _vertices.push_back(vertex);
}

Vertex Graph::getVertex(int id) {
  for (std::vector<Vertex>::iterator it = _vertices.begin(); it != _vertices.end(); ++it) {
    int currentId = it->getId();
    if (currentId == id) return *it;
  }
  return Vertex(id);
}

void Graph::addEdge(int fromVertexID, int toVertexID) {
  if (this->hasEdge(fromVertexID, toVertexID)) return;

  Vertex fromVertex = this->getVertex(fromVertexID);
  Vertex toVertex = this->getVertex(toVertexID);

  _vertices.push_back(fromVertex);
  _vertices.push_back(toVertex);

  Edge edge = Edge(fromVertex, toVertex);
  _edges.push_back(edge);
}

std::vector<graphy::Vertex> Graph::getVertices() {
  return _vertices;
}

std::vector<graphy::Edge> Graph::getEdges() {
  return _edges;
}

void Graph::display() {
  for (std::vector<Edge>::iterator it = _edges.begin(); it != _edges.end(); ++it) {
    it->display();
  }
}

#ifdef __EMSCRIPTEN__
// Binding code
EMSCRIPTEN_BINDINGS(Graph) {
  class_<Graph>("Graph")
      .constructor<>()
      .function("display", &Graph::display)
      .function("addEdge", &Graph::addEdge)
      .function("getVertex", &Graph::getVertex)
      .function("addVertex", &Graph::addVertex)
      .function("hasEdge", &Graph::hasEdge);
}
#endif

};  // namespace graphy
