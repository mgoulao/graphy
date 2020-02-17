const Graphy = require("./dist/graphy.js");

Graphy.init(() => {
	const graph = new Graphy.Graph();
	graph.addEdge(1,2);
	graph.addEdge(1,3);
	graph.addEdge(3,5);
	graph.addEdge(5,4);
	graph.addEdge(2,4);
	const astar = new Graphy.AStar(graph);
	astar.run();
	graph.display();

	// Clean instances
	astar.delete();
	graph.delete();
});
