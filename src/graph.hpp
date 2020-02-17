#ifndef GRAPHY_GRAPH_H
#define GRAPHY_GRAPH_H

#include <vector>
#include "edge.hpp"
#include "vertex.hpp"

namespace graphy {

enum GraphType {
  DIRECTED,
  UNDIRECTED
};

class Graph {
 private:
  std::vector<graphy::Vertex> _vertices;
  std::vector<graphy::Edge> _edges;
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
  Vertex getVertex(int id);
  std::vector<graphy::Vertex> getVertices();
  std::vector<graphy::Edge> getEdges();
  void display();
};

}  // namespace graphy

#endif