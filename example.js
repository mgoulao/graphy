const Graphy = require("./dist/graphy.js");

Graphy.init(() => {
	const graph = new Graphy.Graph();
	graph.addEdge(0,1);
	graph.addEdge(1,2);
	graph.addEdge(2,0);
	graph.addEdge(3,2);
	graph.display();
	graph.delete();
});
