#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void prims(int V, vector<vector<pair<int, int>>> &adj) {

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    vector<int> visited(V, 0);

    // {weight, vertex}
    pq.push({0, 0});

    int totalCost = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    while (!pq.empty()) {

        int wt = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = 1;
        totalCost += wt;

        if (wt != 0)
            cout << u << " - weight " << wt << endl;

        for (auto edge : adj[u]) {

            int v = edge.first;
            int weight = edge.second;

            if (!visited[v]) {
                pq.push({weight, v});
            }
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

    vector<vector<pair<int, int>>> adj(V);

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < E; i++) {

        int u, v, wt;
        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    prims(V, adj);

    return 0;
}