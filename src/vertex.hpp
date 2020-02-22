#ifndef GRAPHY_VERTEX_H
#define GRAPHY_VERTEX_H

#include <vector>

namespace graphy {
class Edge;
class Vertex {
 private:
  int _id;
  std::vector<Edge*> _edges;

 public:
  Vertex();
  Vertex(int id);
  ~Vertex();
  int getId() const;
  void addEdge(Edge* edge);
  Edge getEdge(Vertex vertex);
  std::vector<Edge*> getEdges();
  friend bool operator==(const Vertex& lhs, const Vertex& rhs);
  friend bool operator<(const Vertex& lhs, const Vertex& rhs);
};
}  // namespace graphy

#endif