#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v, wt;
};

int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

    cout << "Enter source, destination and weight:\n";

    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].wt;
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    vector<int> dist(V, 1e9);
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {

            int u = edges[j].u;
            int v = edges[j].v;
            int wt = edges[j].wt;

            if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    bool negativeCycle = false;

    for (int j = 0; j < E; j++) {

        int u = edges[j].u;
        int v = edges[j].v;
        int wt = edges[j].wt;

        if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
            negativeCycle = true;
            break;
        }
    }

    if (negativeCycle) {
        cout << "Negative-weight cycle exists.\n";
    }
    else {
        cout << "No negative-weight cycle exists.\n";

        cout << "Shortest distances from source " << src << ":\n";

        for (int i = 0; i < V; i++) {
            cout << src << " -> " << i << " = " << dist[i] << endl;
        }
    }

    return 0;
}