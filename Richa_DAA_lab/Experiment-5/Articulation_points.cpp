#include <iostream>
#include <vector>
using namespace std;

int timer = 0;

void DFS(int u, int parent, vector<vector<int>>& graph,
         vector<int>& visited, vector<int>& tin,
         vector<int>& low, vector<int>& articulation) {

    visited[u] = 1;
    tin[u] = low[u] = timer++;

    int children = 0;

    for (int v : graph[u]) {

        if (v == parent)
            continue;

        if (visited[v]) {
            // Back edge
            low[u] = min(low[u], tin[v]);
        }
        else {
            // DFS on unvisited vertex
            DFS(v, u, graph, visited, tin, low, articulation);

            low[u] = min(low[u], low[v]);

            // Check articulation point condition
            if (parent != -1 && low[v] >= tin[u])
                articulation[u] = 1;

            children++;
        }
    }

    // Root of DFS tree is articulation point
    if (parent == -1 && children > 1)
        articulation[u] = 1;
}

int main() {

    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> graph(V);

    cout << "Enter edges:\n";

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> visited(V, 0);
    vector<int> tin(V);
    vector<int> low(V);
    vector<int> articulation(V, 0);

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            DFS(i, -1, graph, visited, tin, low, articulation);
    }

    cout << "\nArticulation Points are: ";

    bool found = false;

    for (int i = 0; i < V; i++) {
        if (articulation[i]) {
            cout << i << " ";
            found = true;
        }
    }

    if (!found)
        cout << "None";

    cout << endl;

    return 0;
}