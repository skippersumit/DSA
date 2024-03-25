#include <bits/stdc++.h>
using namespace std;

bool dfsCheck(int node, vector<int>adj[], int vis[], int pathVis[]) {
    vis[node] = 1;
    pathVis[node] = 1;

    // check for adjacent edges
    for (auto it : adj[node]) {
        if (!vis[it]) { // node is not visited
            if (dfsCheck(it, adj, vis, pathVis) == true)
                return true;
        } else if (pathVis[it] ) { // checks if node is visited previously, but if visited on the same path then cycle is there
            return true;
        }
    }
    pathVis[node] = 0; // reset the pathVis for node;  this value will be 1 for nodes visited on the same path in dfs call tree
    return false;
}

bool isCyclic(int V, vector<int>adj[]) {
    int vis[V] = {0};
    int pathVis[V] = {0};

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (dfsCheck(i, adj, vis, pathVis) == true) return true;
        }
    }
    return false;
}

int main()
{
    vector<int> adj[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
    int V = 11;

    /*
    https://takeuforward.org/data-structure/detect-cycle-in-a-directed-graph-using-dfs-g-19/
    We need an approach that takes care of nodes visited in same path to check for cycles
    Because there can be nodes visited already but not on the same path and we cannot comment
    that it has cycle or not.
    */
    bool ans = isCyclic(V, adj);

    if (ans)
        cout << "Graph is having a cycle\n";
    else
        cout << "Graph is not having a cycle\n";
    
    return 0;
}
