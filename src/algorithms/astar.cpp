#ifdef __EMSCRIPTEN__
#include <emscripten/bind.h>
#endif
#include <algorithm>
#include <limits>
#include <map>
#include <set>
#include <vector>
#include "../graph.hpp"

namespace graphy {
namespace algorithms {

#ifdef __EMSCRIPTEN__
using namespace emscripten;
#endif

class AStar {
 private:
  Graph _graph;

 public:
  AStar(Graph graph) {
    _graph = graph;
  }

  ~AStar() {}

  // Based on https://en.wikipedia.org/wiki/A*_search_algorithm#Pseudocode

  std::vector<Edge> run(int originVertexId, int destinationVertexId) {
    Vertex origin = _graph.getVertex(originVertexId);
    Vertex destination = _graph.getVertex(destinationVertexId);

    std::vector<Vertex> openSet;
    std::map<Vertex, Vertex> cameFrom;

    // For node n, gScore[n] is the cost of the cheapest path from start to n currently known.
    std::map<Vertex, int> gScore;  // map with default value of Infinity
    gScore.insert({origin, 0});

    initializeGScore(gScore);

    // For node n, fScore[n] := gScore[n] + h(n).
    static std::map<Vertex, int> fScore;  // map with default value of Infinity
    fScore.insert({origin, heuristic(origin, destination)});
    struct CompareVertices {
      bool operator()(Vertex vertexA, Vertex vertexB) {
        return fScore.at(vertexA) < fScore.at(vertexB);
      }
    };

    while (openSet.size()) {
      Vertex current = openSet.at(0);  // the node in openSet having the lowest fScore[] value
      if (current == destination) return reconstruct_path(cameFrom, current);
      std::vector<Vertex>::iterator it = openSet.begin();
      openSet.erase(it);

      for (std::vector<Edge*>::iterator it = current.getEdges().begin(); it != current.getEdges().end(); ++it) {
        Edge currentEdge = **it;
        Vertex nextVertex = currentEdge.getOtherVertex(current);
        // d(current,neighbor) is the weight of the edge from current to neighbor
        // tentative_gScore is the distance from start to the neighbor through current
        const int tentative_gScore = gScore.at(current) + currentEdge.getCost();
        if (tentative_gScore < gScore.at(nextVertex)) {
          // This path to neighbor is better than any previous one. Record it!
          cameFrom.insert({nextVertex, current});
          gScore.at(nextVertex) = tentative_gScore;
          fScore.insert({nextVertex, gScore.at(nextVertex) + heuristic(nextVertex, destination)});
          if (vectorContainsVertex(openSet, nextVertex)) {
            openSet.push_back(nextVertex);
          }
        }
      }
      std::sort(openSet.begin(), openSet.end(), CompareVertices());
    }
    // Open set is empty but goal was never reached
    return {};
  }

 private:
   void initializeGScore(std::map<Vertex, int> gScore) {
    for (std::map<Vertex, int>::iterator it = gScore.begin(); it != gScore.end(); ++it) {
      it->second = std::numeric_limits<int>::max();
    }
  }

  bool vectorContainsVertex(std::vector<Vertex> vector, Vertex vertex) {
    for (std::vector<Vertex>::iterator it = vector.begin(); it != vector.end(); ++it) {
      Vertex v = *it;
      if (vertex == v) return true;
    }
    return false;
  }

  int distanceBetween(Vertex first, Vertex second) {
    for (std::vector<Edge*>::iterator it = first.getEdges().begin(); it != first.getEdges().end(); ++it) {
      Edge edge = **it;
      if (edge.getOtherVertex(first) == second)
        return edge.getCost();
    }
    return std::numeric_limits<int>::max();
  }

  int heuristic(Vertex origin, Vertex destination) {
    return 1;
  }

  std::vector<Edge> reconstruct_path(std::map<Vertex, Vertex> cameFrom, Vertex current) {
    std::vector<Edge> totalPath;
    while (!cameFrom.empty()) {
      Vertex previous = current;
      current = cameFrom.at(current);
      Edge edge = current.getEdge(previous);
      totalPath.push_back(edge);
    }
    return totalPath;
  }
};

#ifdef __EMSCRIPTEN__
// Binding code
EMSCRIPTEN_BINDINGS(AStart) {
  class_<AStart>("AStart")
      .constructor<Graph>()
      .function("run", &AStar::run);
}
#endif

};  // namespace algorithms
};  // namespace graphy