#include <bits/stdc++.h>
using namespace std;

bool check(int start, int V, vector<int>adj[], int color[]) {
    queue<int> q;
    q.push(start);
    color[start] = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto it : adj[node]) {
            // if the adjacent node is yet not colored
            // you will give the opposite color of the node
            if (color[it] == -1) {

                color[it] = !color[node];
                q.push(it);
            }
            // is the adjacent guy having the same color
            // someone did color it on some other path
            else if (color[it] == color[node]) {
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(int V, vector<int>adj[]) {
    int color[V];
    for (int i = 0; i < V; i++) color[i] = -1;

    for (int i = 0; i < V; i++) {
        // if not coloured
        if (color[i] == -1) {
            if (check(i, V, adj, color) == false) {
                return false;
            }
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
