const Graphy = require("./dist/graphy.js");

Graphy.init(() => {
	const graph = new Graphy.Graph();
	graph.addEdge(1,2);
	graph.addEdge(1,3);
	graph.addEdge(3,5);
	graph.addEdge(5,4);
	graph.addEdge(2,4);
	const astar = new Graphy.AStar(graph);
	const a = astar.run(1, 4);
	a.push_back(2);
	console.log(a[0]);
	graph.display();

	// Clean instances
	astar.delete();
	graph.delete();
});
