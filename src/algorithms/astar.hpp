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
  virtual ~AStar();

  std::vector<Edge> run(int originVertexId, int destinationVertexId);
  virtual int heuristic(Vertex origin, Vertex destination);

 private:
  void initializeGScore(std::map<Vertex, int>* gScore);

  bool vectorContainsVertex(std::vector<Vertex*> vector, Vertex* vertex);

  int distanceBetween(Vertex* first, Vertex* second);

  std::vector<Edge> reconstruct_path(std::map<Vertex*, Vertex*> cameFrom, Vertex* current);
};

};  // namespace algorithms
};  // namespace graphy

#endif