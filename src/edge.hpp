#ifndef GRAPHY_EDGE_H
#define GRAPHY_EDGE_H

#include "vertex.hpp"

namespace graphy {
class Edge {
 private:
  Vertex* _from;
  Vertex* _to;
  int _cost = 0;

 public:
  Edge();
  Edge(Vertex* from, Vertex* to, int cost);
  Edge(Vertex* from, Vertex* to);
  ~Edge();
  Vertex* getFromVertex();
  Vertex* getToVertex();
  int getCost();
  Vertex* getOtherVertex(Vertex vertex);
  void display();


};
}  // namespace graphy

#endif