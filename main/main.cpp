#include <iostream>
#include "graph.h"

using namespace std;

int main(int argc, char *argv[])
{
    Graph G = Graph();

    G.addVertex(1);
    G.addVertex(2);
    G.addVertex(3);
    G.addVertex(4);
    G.addVertex(5);
    G.addVertex(6);

    G.addEdge(1, 2);
    G.addEdge(1, 3);
    G.addEdge(2, 4);
    G.addEdge(3, 5);
    G.addEdge(4, 6);
    G.addEdge(5, 6);

    auto n = [&] (int n) { cout << "Visited: " << n << endl; };
    auto f = [&] (int f, int t) { };

    bfs(G, 1, n, f);
}
