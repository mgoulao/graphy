#ifndef GRAPHY_ASTAR_H
#define GRAPHY_ASTAR_H

#include <map>
#include <vector>
#include "../graph.hpp"

namespace graphy {
namespace algorithms {

class AStar {
 private:
  Graph _graph;

 public:
  AStar(Graph graph);
  ~AStar();

  std::vector<Edge> run(int originVertexId , int destinationVertexId);

 private:
  void initializeGScore(std::map<Vertex, int>* gScore);

  bool vectorContainsVertex(std::vector<Vertex*> vector, Vertex* vertex);

  int distanceBetween(Vertex* first, Vertex* second);

  int heuristic(Vertex* origin, Vertex* destination);

  std::vector<Edge> reconstruct_path(std::map<Vertex*, Vertex*> cameFrom, Vertex* current);
};

};  // namespace algorithms
};  // namespace graphy

#endif