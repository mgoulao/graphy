const Module = require("./graphy_module.js");

class Graphy {

	static get Graph() {
		return Graphy._Graph;
	}

	static set Graph(graph) {
		Graphy._Graph = graph;
	}

	static get AStar() {
		return Graphy._AStar;
	}

	static set AStar(astar) {
		Graphy._AStar = astar;
	}

  static init(onLoadCallback) {
    Module["onRuntimeInitialized"] = () => {
			Graphy.Graph = Module.Graph;
			Graphy.AStar = Module.AStar;
			onLoadCallback();
		};
  }
}

module.exports = Graphy;
