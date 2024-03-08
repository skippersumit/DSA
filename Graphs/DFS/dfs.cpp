#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>adj[],int vis[],vector<int>&dfsList){
    vis[node] = 1;
    dfsList.push_back(node);

    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,dfsList);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]){
    int vis[V] = {0};
    int start = 0;

    vector<int>dfsList;

    dfs(start,adj,vis,dfsList);
    return dfsList;
}

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main()
{
    //Depth first Search
    vector <int> adj[5];
    
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);

    vector <int> ans = dfsOfGraph(5, adj);
    printAns(ans);
    return 0;
}
