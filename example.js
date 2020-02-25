const Graphy = require("./dist/graphy.js");

Graphy.init(() => {
	// Example from https://www.youtube.com/watch?v=vP5TkF0xJgI
	
	const graph = new Graphy.Graph();
	graph.addEdgeWithCost(1,2,6);
	graph.addEdgeWithCost(1,10,3);
	graph.addEdgeWithCost(2,3,3);
	graph.addEdgeWithCost(2,4,2);
	graph.addEdgeWithCost(3,4,1);
	graph.addEdgeWithCost(3,5,5);
	graph.addEdgeWithCost(4,5,8);
	graph.addEdgeWithCost(5,6,6);
	graph.addEdgeWithCost(5,7,5);
	graph.addEdgeWithCost(7,6,3);
	graph.addEdgeWithCost(6,8,3);
	graph.addEdgeWithCost(6,9,2);
	graph.addEdgeWithCost(8,10,1);
	graph.addEdgeWithCost(10,9,7);

	graph.display();

	const astar = new Graphy.AStar(graph);
	const result = astar.run(1, 7);

	for(let i = 0; i < result.size(); i++) {
		result.get(i).display();
	}

	// Clean instances
	astar.delete();
	graph.delete();
});
