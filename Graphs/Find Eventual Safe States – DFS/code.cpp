#include <bits/stdc++.h>
using namespace std;

bool dfsCheck(int node,vector<int>adj[], int vis[], int pathVis[], int check[]){
    vis[node] = 1;
    pathVis[node] = 1;
    check[node] = 0;

    // traverse for adjacent nodes
    for(auto it : adj[node]){

        // node is not visited
        if(!vis[it]){
            if(dfsCheck(it,adj,vis,pathVis,check) == true){
                check[node] = 0;
                return true;
            }
        } else if(pathVis[it]){
            // if node has been previously visited, but it has to be visited on the same path
            check[node] = 0;
            return true;

        }
    }
    check[node] = true;
    pathVis[node] = 0;
    return false;
}

vector<int> eventualSafeNodes(int V, vector<int>adj[]){
    int vis[V] = {0};
    int pathVis[V] = {0};
    int check[V] = {0};

    vector<int> safeNodes;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfsCheck(i,adj,vis,pathVis,check);
        }
    }

    for(int i=0;i<V;i++){
        if(check[i] == 1) safeNodes.push_back(i);
    }

    return safeNodes;
}

int main()
{
    /*
        Problem Statement: A directed graph of V vertices and E edges is given in the form of an adjacency list adj.
        Each node of the graph is labeled with a distinct integer in the range 0 to V – 1. A node is a terminal node
        if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to
        a terminal node. You have to return an array containing all the safe nodes of the graph. The answer should be
        sorted in ascending order.

    Terminal Node is node with outDegree 0

    Give me all the safe nodes in the graph
    */

    vector<int> adj[12] = {{1}, {2}, {3}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10}, {8}, {9} };
    int V = 12;

    vector<int> safeNodes = eventualSafeNodes(V, adj);

    cout << "Safe nodes: " << endl;

    for (auto node : safeNodes) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}
