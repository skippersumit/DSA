#include <bits/stdc++.h>
using namespace std;
/*
Time Complexity: O(N) + O(V+2E), Where O(N) is for outer loop and inner loop runs in total a single DFS over entire graph,
and we know DFS takes a time of O(V+2E). 
Space Complexity: O(N) + O(N),Space for recursion stack space and visited array.
*/

void dfs(int node, vector<int> adjLs[], int vis[]) {
    // mark the node as visited
    vis[node] = 1; 
    for(auto it: adjLs[node]) {
        if(!vis[it]) {
            dfs(it, adjLs, vis); 
        }
    }
}

int numProvinces(vector<vector<int>>adj, int V){
    vector<int>adjList[V];

    //to change adjacency matrix to adjacency list
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(adj[i][j] == 1 && i!=j){
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }

    int vis[V] = {0};
    int cnt = 0;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            cnt++;
            dfs(i,adjList,vis);
        }
    }

    return cnt;
}

int main()
{
    // Number of Traversals is the answer, done using both bfs and dfs
    vector<vector<int>> adj
    {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };
    cout << numProvinces(adj,3) << endl;
    return 0;
}
