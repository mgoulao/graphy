#ifdef __EMSCRIPTEN__
#include <emscripten/bind.h>
#endif
#include "edge.hpp"
#include <iostream>
#include "vertex.hpp"

namespace graphy {

#ifdef __EMSCRIPTEN__
using namespace emscripten;
#endif

Edge::Edge() {
}

Edge::Edge(Vertex* from, Vertex* to, int cost) {
  _from = from;
  _to = to;
  _cost = cost;
}

Edge::Edge(Vertex* from, Vertex* to) : Edge(from, to, 0){};

Edge::~Edge() {
}

Vertex* Edge::getFromVertex() {
  return _from;
}

Vertex* Edge::getToVertex() {
  return _to;
}

int Edge::getCost() {
  return _cost;
}

Vertex* Edge::getOtherVertex(Vertex vertex) {
  if (vertex == *_from)
    return _to;
  else if (vertex == *_to)
    return _from;
  return NULL;
}

void Edge::display() {
  std::cout << _from->getId() << " <---> " << _to->getId() << ", cost: " << _cost << "\n";
}

#ifdef __EMSCRIPTEN__
// Binding code
EMSCRIPTEN_BINDINGS(Edge) {
  class_<Edge>("Edge")
      .constructor<>()
      .function("getCost", &Edge::getCost)
      .function("display", &Edge::display);
}
#endif

}  // namespace graphy