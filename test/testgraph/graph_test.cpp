#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "graph.h"

using namespace std;

TEST_CASE( "Test  Graph BFS", "[basic]") {
    Graph graph = Graph();

    cout << "Graph Solver" << endl;

    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addVertex(4);
    graph.addVertex(5);
    graph.addVertex(6);

    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 5);
    graph.addEdge(2, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 6);
    graph.addEdge(5, 6);
    
    bfs(graph, 1);

    graph.destroy();
}

TEST_CASE( "Test  Graph DFS", "[basic]") {
    Graph graph = Graph();

    cout << "Graph Solver" << endl;

    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addVertex(4);
    graph.addVertex(5);
    graph.addVertex(6);

    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 5);
    graph.addEdge(2, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 6);
    graph.addEdge(5, 6);
    
    dfs(graph, 1);

    graph.destroy();
}

TEST_CASE( "Test Graph Constuctor", "[constructor]" ) {
    Graph g = Graph();

    g.addVertex(1);
    REQUIRE(g.getVertex(1)->getId() == 1);
}
