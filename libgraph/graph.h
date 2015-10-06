#include <exception>
#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

#ifndef _GRAPH_H_
#define _GRAPH_H_

using namespace std;

class Edge {
    int from;
    int to;
    std::map<std::string, double> data;

    public:
        Edge(int, int);
        ~Edge();
        int getFrom() { return from; };
        int getTo() { return to; };

        void setInfo(std::string, double);
        double getInfo(std::string);

        void dumpInfo();
};

class Vertex {
    int id;
    std::vector<Edge*> edges;

    public:
        Vertex();
        Vertex(int);
        ~Vertex();
        int getId() { return id; };

        Edge* find(int);
        void addEdge(int);
        std::vector<Edge*> getEdges();
};

class Graph {
    std::unordered_map<int, Vertex*> vertexes;

    public:
        Graph();
        ~Graph();

        int vertexesSize();
        int edgesSize();

        void addVertex(int);
        Vertex *getVertex(int);

        void addEdge(int, int);
        void setEdgeInfo(int, int, string, double);
        double getEdgeInfo(int, int, string);
};

void bfs(Graph &graph, int first,
         std::function<void(int)> node,
         std::function<void(int, int)> func);

void dfs(Graph &graph, int first,
         std::function<void(int)> node,
         std::function<void(int, int)> func);
#endif
