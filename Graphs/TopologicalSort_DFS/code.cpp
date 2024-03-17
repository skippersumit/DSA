#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int vis[], stack<int> &st,vector<int> adj[]) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) dfs2(it, vis, st, adj);
    }
    st.push(node);
}

//Function to return list containing vertices in Topological order.
vector<int> topoSort(int V, vector<int> adj[])
{
    int vis[V] = {0};
    stack<int> st;
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(i, vis, st, adj);
        }
    }

    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main()
{
    /*
         In topological sorting, node u will always appear before node v if there is a directed edge
         from node u towards node v(u -> v).
    */
    vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
    int V = 6;
    vector<int> ans = topoSort(6, adj);

    cout << "After topological Sorting" << endl;
    for (auto node : ans) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}
