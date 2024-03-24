#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int col, int color[], vector<int> adj[]) {
    color[node] = col;

    // traverse adjacent nodes
    for (auto it : adj[node]) {
        // if uncoloured
        if (color[it] == -1) {
            if (dfs(it, !col, color, adj) == false) return false;
        }
        // if previously coloured and have the same colour
        else if (color[it] == col) {
            return false;
        }
    }

    return true;
}

bool isBipartite(int V, vector<int>adj[]) {
    int color[V];
    for (int i = 0; i < V; i++) color[i] = -1;

    // for connected components
    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            if (dfs(i, 0, color, adj) == false)
                return false;
        }
    }
    return true;
}


void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    vector<int>adj[4];

    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);

    // any graph with odd length cycle can never be a bipartite graph
    if (isBipartite(4, adj))
        cout << "Graph is Bipartite Graph\n";
    else
        cout << "Graph is not Bipartite Graph\n";

    return 0;
}
