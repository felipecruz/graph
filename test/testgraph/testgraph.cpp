#include "graph.h"
#include "testgraph.h"

GraphTest::GraphTest() {}

GraphTest::~GraphTest() {};

void GraphTest::SetUp() {};

void GraphTest::TearDown() {};

TEST_F(GraphTest, Constructor) {
    Graph graph = Graph();

    EXPECT_EQ(graph.vertexesSize(), 0);
    EXPECT_EQ(graph.getVertex(1), nullptr);
}

TEST_F(GraphTest, AddVertex) {
    Graph graph = Graph();
    graph.addVertex(1);

    EXPECT_EQ(graph.vertexesSize(), 1);
}

TEST_F(GraphTest, GetVertex) {
    Graph graph = Graph();
    graph.addVertex(1);

    EXPECT_NE(graph.getVertex(1), nullptr);
    EXPECT_EQ(graph.getVertex(1)->getId(), 1);
}

TEST_F(GraphTest, AddEdge) {
    Graph graph = Graph();
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);

    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    EXPECT_EQ(graph.edgesSize(), 2);
}

TEST_F(GraphTest, AddEdgeInfo) {
    Graph graph = Graph();
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addEdge(1, 2);

    graph.setEdgeInfo(1, 2, "value", 10.0);
    EXPECT_EQ(graph.getEdgeInfo(1, 2, "value"), 10.0);
}

TEST_F(GraphTest, VertexConstructor) {
    Vertex v1 = Vertex();
    Vertex v2(10);

    EXPECT_EQ(v2.getId(), 10);
}

TEST_F(GraphTest, VertexAddEdge) {
    Vertex v(1);
    v.addEdge(2);

    EXPECT_EQ(v.getEdges().size(), 1);
}

TEST_F(GraphTest, VertexFind) {
    Vertex v(1);
    v.addEdge(2);

    EXPECT_NE(v.find(2), nullptr);
    EXPECT_EQ(v.find(1), nullptr);
}

TEST_F(GraphTest, EdgeConstructor) {
    Edge e = Edge(1, 2);

    EXPECT_EQ(1, e.getFrom());
    EXPECT_EQ(2, e.getTo());
}

TEST_F(GraphTest, EdgeAddInfo) {
    Edge e = Edge(1, 2);
    e.setInfo("test", 123456789.0);

    EXPECT_EQ(123456789.0, e.getInfo("test"));
    EXPECT_EQ(-1, e.getInfo("other"));

}

TEST_F(GraphTest, BFS) {
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

    int found[6];
    int c = 0;
    vector<int> expected({1, 2, 3, 4, 5, 6});

    auto n = [&] (int n) { found[c++] = n; };
    auto f = [&] (int f, int t) { };

    bfs(G, 1, n, f);

    for (int i = 0; i < 6; i++) {
        EXPECT_EQ(found[i], expected[i]);
    }
}

TEST_F(GraphTest, DFS) {
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

    int found[6];
    int c = 0;
    vector<int> expected({1, 3, 5, 6, 2, 4});

    auto n = [&] (int n) { found[c++] = n; };
    auto f = [&] (int f, int t) { };

    dfs(G, 1, n, f);

    for (int i = 0; i < 6; i++) {
        EXPECT_EQ(found[i], expected[i]);
    }
}
