#include "graph.h"

using namespace std;

Edge::Edge(int _from, int _to) {
    from = _from;
    to = _to;
    data = std::map<std::string, double>();
}

Edge::~Edge() {
    cout << "e: (" << from << " -> " << to << ") deleted" << endl;
}

double Edge::getInfo(std::string key) {
    if (data.find(key) != data.end())
        return data[key];
    return -1;
}

void Edge::setInfo(std::string key, double value) {
    data[key] = value;
}

void Edge::dumpInfo() {
    for (auto o: data) {
        cout << "  " << o.first << " " << o.second << endl;
    }
}

/////////////////////////////////////////////////////////

Vertex::Vertex() {
    edges = std::vector<Edge*>();
}

Vertex::~Vertex() {
    for (auto e: edges) {
        delete e;
    }
}

Vertex::Vertex(int _id) {
    id = _id;
    edges = std::vector<Edge*>();
}

Edge* Vertex::find(int id) {
    for (auto e : edges) {
        if (e->getTo() == id) {
            return e;
        }
    }
    return nullptr;
}

void Vertex::addEdge(int to) {
    if (find(to) == nullptr) {
        Edge *edge = new Edge(getId(), to);
        edges.push_back(edge);
    }
}

std::vector<Edge*> Vertex::getEdges() {
    return edges;
}

/////////////////////////////////////////////////////////

Graph::Graph(bool _unidirected) {
    vertexes = std::unordered_map<int, Vertex*>();
    unidirected = _unidirected;
}

Graph::~Graph() {
    for (auto v : vertexes) {
        delete v.second;
    }
}

void Graph::addVertex(int id) {
    Vertex *v = new Vertex(id);
    vertexes[id] = v;
}

Vertex* Graph::getVertex(int id) {
    return vertexes[id];
}


int Graph::vertexesSize() {
    return vertexes.size();
}

int Graph::edgesSize() {
    int edges = 0;

    for (auto v : vertexes) {
        edges += v.second->getEdges().size();
    }

    return edges;
}

void Graph::addEdge(int from, int to) {
    Vertex *vfrom = getVertex(from);

    if (vfrom != nullptr) {
        vfrom->addEdge(to);
    }

    if (unidirected) {
        Vertex *vto = getVertex(to);

        if (vto != nullptr) {
            vto->addEdge(from);
        }
    }
}

void Graph::setEdgeInfo(int from, int to, std::string key, double value) {
    Vertex *v = getVertex(from);
    Edge* e = v->find(to);
    e->setInfo(key, value);
}

double Graph::getEdgeInfo(int from, int to, string key) {
    Vertex *v = getVertex(from);
    Edge* e = v->find(to);
    return e->getInfo(key);
}

void bfs(Graph *graph, int first,
         function < void(int) > node,
         function < void(int, int) > func) {
    bool *visited = new bool[graph->vertexesSize()];
    std::queue<Vertex*> queue;

    for (int i = 0; i < graph->vertexesSize(); i++) visited[i] = false;

    queue.push(graph->getVertex(first));
    visited[first] = true;

    while (!queue.empty()) {
        Vertex* v = queue.front();
        queue.pop();
        if (v == nullptr) { continue; }
        node(v->getId());
        for (auto e: v->getEdges()) {
            if (!visited[e->getTo()]) {
                func(v->getId(), e->getTo());
                queue.push(graph->getVertex(e->getTo()));
                visited[e->getTo()] = true;
            }
        }
    }

    delete[] visited;
}

void dfs(Graph *graph, int first,
         function < void(int) > node,
         function < void(int, int) > func) {
    bool *visited = new bool[graph->vertexesSize()];
    std::stack<Vertex*> stack;

    stack.push(graph->getVertex(first));
    visited[first] = true;

    while (!stack.empty()) {
        Vertex* v = stack.top();
        node(v->getId());
        stack.pop();
        for (auto e: v->getEdges()) {
            if (!visited[e->getTo()]) {
                func(v->getId(), e->getTo());
                stack.push(graph->getVertex(e->getTo()));
                visited[e->getTo()] = true;
            }
        }
    }

    delete[] visited;
}

