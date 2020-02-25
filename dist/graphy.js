const Module = require("./graphy_module.js");

class Graphy {
  static get Graph() {
    return Graphy._Graph;
  }

  static get AStar() {
    return Graphy._AStar;
  }

  static init(onLoadCallback) {
    Module["onRuntimeInitialized"] = () => {
      Graphy._Graph = Module.Graph;
      Graphy._AStar = Module.AStar;
      onLoadCallback();
    };
  }
}

module.exports = Graphy;
