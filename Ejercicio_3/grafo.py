from dijkstar import *


class Grafo:

    def __init__(self):
        self.nodos = ["A", "B", "C", "D", "E", "F", "G"]
        self.grafo = Graph()

    def llena_grafo(self):
        self.grafo.add_node("A", {"B": 3, "F": 8, "G": 4})
        self.grafo.add_node("B", {"A": 3, "C": 2, "D": 13})
        self.grafo.add_node("C", {"B": 2, "D": 3, "E": 15})
        self.grafo.add_node("D", {"B": 13, "C": 3, "E": 1, "F": 2})
        self.grafo.add_node("E", {"C": 15, "D": 1, "F": 4})
        self.grafo.add_node("F", {"A": 8, "D": 2, "E": 4, "G": 1})
        self.grafo.add_node("G", {"A": 4, "F": 1})
