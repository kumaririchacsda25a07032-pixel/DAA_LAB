#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, wt;
};

bool compare(Edge a, Edge b) {
    return a.wt < b.wt;
}

int findParent(int node, vector<int> &parent) {

    if (parent[node] == node)
        return node;

    return parent[node] = findParent(parent[node], parent);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {

    u = findParent(u, parent);
    v = findParent(v, parent);

    if (u == v)
        return;

    if (rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if (rank[u] > rank[v]) {
        parent[v] = u;
    }
    else {
        parent[v] = u;
        rank[u]++;
    }
}

void kruskal(int V, vector<Edge> &edges) {

    // Sort edges according to weight
    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(V);
    vector<int> rank(V, 0);

    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    int totalCost = 0;
    int count = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (auto edge : edges) {

        int u = edge.u;
        int v = edge.v;
        int wt = edge.wt;

        // Check if adding this edge creates a cycle
        if (findParent(u, parent) != findParent(v, parent)) {

            cout << u << " - " << v << " : " << wt << endl;

            totalCost += wt;
            count++;

            unionSet(u, v, parent, rank);

            // MST contains V-1 edges
            if (count == V - 1)
                break;
        }
    }

    cout << "Total cost of MST = " << totalCost << endl;
}

int main() {

    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges;

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < E; i++) {

        int u, v, wt;

        cin >> u >> v >> wt;

        edges.push_back({u, v, wt});
    }

    kruskal(V, edges);

    return 0;
}