#include <vector>
#include <iostream>
#include "graph.hpp"
#include "vertex.hpp"
#include "edge.hpp"
#include "./algorithms/astar.hpp"

namespace algo = graphy::algorithms;

int main() {
	graphy::Graph graph = graphy::Graph();
	graph.addEdge(1,2);
	graph.addEdge(1,3);
	graph.addEdge(3,5);
	graph.addEdge(5,4);
	graph.addEdge(2,4);
	graph.display();

	algo::AStar astar = algo::AStar(graph);
	std::vector<graphy::Edge> result =	astar.run(1, 4);

	std::cout << "Size: " << result.size() << "\n";

	return 0;
}