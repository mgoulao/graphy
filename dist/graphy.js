const Module = require("./graphy_module.js");

class Graphy {

	static get Graph() {
		return Graphy._Graph;
	}

	static set Graph(graph) {
		Graphy._Graph = graph;
	}

  static init(onLoadCallback) {
    Module["onRuntimeInitialized"] = () => {
			Graphy.Graph = Module.Graph;
			onLoadCallback();
		};
  }
}

module.exports = Graphy;
