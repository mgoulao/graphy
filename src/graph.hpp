#ifndef GRAPHY_GRAPH_H
#define GRAPHY_GRAPH_H

#include <vector>
#include <list>
#include "edge.hpp"
#include "vertex.hpp"

namespace graphy {

enum GraphType {
  DIRECTED,
  UNDIRECTED
};

class Graph {
 private:
  std::list<graphy::Vertex> _vertices;
  std::list<graphy::Edge> _edges;
  GraphType _type;

 public:
  Graph();
  Graph(GraphType graphType);
  ~Graph();
  void print();
  GraphType getType();
  bool hasVertex(int id);
  bool hasEdge(int fromVertexID, int toVertexID);
  void addVertex(int id);
  void addEdge(int fromVertexID, int toVertexID);
  void addEdge(int fromVertexID, int toVertexID, int cost);
  Vertex* getVertex(int id);
  Vertex createVertex(int id);
  std::list<graphy::Vertex> getVertices();
  std::list<graphy::Edge> getEdges();
  void display();
};

}  // namespace graphy

#endif