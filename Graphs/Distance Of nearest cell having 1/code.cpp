#include <bits/stdc++.h>
using namespace std;

//bfs based
/*
Time Complexity: O(NxM + NxMx4) ~ O(N x M)
For the worst case, the BFS function will be called for (N x M) nodes, and for every node, we are traversing
for 4 neighbors, so it will take O(N x M x 4) time.

Space Complexity: O(N x M) + O(N x M) + O(N x M) ~ O(N x M)
*/
vector<vector<int>>nearest(vector<vector<int>>&grid) {
    int n = grid.size();
    int m = grid[0].size();

    // visited and distance array
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, 0));

    queue<pair<pair<int, int>, int>>q; // coordinate,steps

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            } else {
                vis[i][j] = 0;
            }
        }
    }

    int dx[] = { -1, 0, +1, 0};
    int dy[] = {0, +1, 0, -1};

    while (!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();
        dist[row][col] = steps;

        for (int i = 0; i < 4; i++) {
            int nrow = row + dx[i];
            int ncol = col + dy[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && (vis[nrow][ncol] == 0)) {
                vis[nrow][ncol] = 1;
                q.push({{nrow, ncol}, steps + 1});
            }
        }
    }
    return dist;
}

int main()
{
    vector<vector<int>>grid{
        {0, 1, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 1, 1}
    };

    vector<vector<int>>grid2{
        {{1, 0, 1}, {1, 1, 0}, {1, 0, 0}}
    };

    vector<vector<int>> ans = nearest(grid);
    cout << "Graph 1: " << endl;
    for (auto i : ans) {
        for (auto j : i)
            cout << j << " ";
        cout << "\n";
    }

    cout << "Graph 2: " << endl;
    ans = nearest(grid2);
    for (auto i : ans) {
        for (auto j : i)
            cout << j << " ";
        cout << "\n";
    }
    return 0;
}
