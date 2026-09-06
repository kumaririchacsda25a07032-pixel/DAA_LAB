#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor])
            dfs(neighbor, adj, visited);
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);
    
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(V, false);
    int components = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            components++;
            cout << "Component " << components << ": ";
            dfs(i, adj, visited);
            cout << endl;
        }
    }

    cout << "Total Connected Components: " << components << endl;

    return 0;
}