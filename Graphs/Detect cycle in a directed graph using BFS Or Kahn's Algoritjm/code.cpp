#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(int n, vector<int>adj[]) {
    queue<int>q;
    vector<int>indegree(n, 0);

    for (int i = 0; i < n; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int>topo; // this is the final answer that contains topological sorting element

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0) {
                q.push(it);
            }
        }
    }
    return topo;
}

int main()
{
    vector<int> adj[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
    int V = 11;

    vector<int> adj2[6] = {{}, {2}, {3}, {4, 5}, {2}, {}};
    int V2 = 6;

    /*
    https://takeuforward.org/data-structure/detect-a-cycle-in-directed-graph-topological-sort-kahns-algorithm-g-23/
    Kahn's Algorithm

    topo sort is applicable for DAG( Directed Acyclic Graph)
    Apply TopoSort and if it fails ( Size of toposort is not n) then cycle is there.
    */
    vector<int>topoSortArr = topologicalSort(V, adj);
    cout << "Printing topoSortArr, if topoSortArr size is same as V then its DAG" << endl;
    for (auto x : topoSortArr) {
        cout << x << " ";
    }
    cout << endl;
    if (topoSortArr.size() != V)
        cout << "Graph is having a cycle\n";
    else
        cout << "Graph is not having a cycle\n";

    topoSortArr = topologicalSort(V2, adj2);

    cout << "Printing topoSortArr, if topoSortArr size is same as V then its DAG" << endl;
    for (auto x : topoSortArr) {
        cout << x << " ";
    }
    cout << endl;
    if (topoSortArr.size() != V2)
        cout << "Graph2 is having a cycle\n";
    else
        cout << "Graph2 is not having a cycle\n";
    return 0;
}
