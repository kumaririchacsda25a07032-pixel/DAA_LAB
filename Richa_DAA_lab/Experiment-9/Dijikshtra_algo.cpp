#include<vector>
#include<queue>
#include<iostream>
#include<climits>
using namespace std;

vector<int> dijkstra(int V,vector<vector<pair<int,int>>> &adj,int src) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, 
                   greater<pair<int,int>>> pq;
    vector<int> dist(V,INT_MAX);
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty()) {
            auto itt=pq.top();
            pq.pop();
            int d=itt.first;
            int node=itt.second;
            for(auto it:adj[node]) {
                int nextnode=it.first;
                int weight=it.second;
                if(dist[node]+weight<dist[nextnode]) {
                    dist[nextnode]=dist[node]+weight;
                    pq.push({dist[nextnode],nextnode});
                }
            }
        }
        return dist;
}

int main() {
    int V, E;
    cout<<"Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pair<int,int>>> adj(V);

    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int src;
    cin >> src;

    vector<int> dist = dijkstra(V, adj, src);

    for(int i = 0; i < V; i++) {
        cout << i << " -> " << dist[i] << endl;
    }

    return 0;

}