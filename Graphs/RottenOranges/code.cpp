#include <bits/stdc++.h>
#define pii pair<int,int>
#define piii pair<pii,int>
using namespace std;

//BFS -> levelwise traversal
int orangesRotting(vector < vector < int >> & grid) {
    int n = grid.size();
    int m = grid[0].size();

    //{{row,col},time}
    queue<piii>q;
    int vis[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            } else {
                vis[i][j] = 0;
            }
        }
    }

    int tm = 0;
    int dx[4] = { -1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        tm = max(tm, t);
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nrow = r + dx[i];
            int ncol = c + dy[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && (vis[nrow][ncol] != 2) && (grid[nrow][ncol] == 1)) {
                q.push({{nrow, ncol}, t + 1});
                vis[nrow][ncol] = 2;
            }
        }
    }

    // Print Visited array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout<<vis[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    // Print Grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }

    //check all are visited or not
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] != 2 && grid[i][j] == 1) return -1;
        }
    }

    return tm;
}

int main()
{
    /*
    Problem Statement: Given a grid of dimension N x M where each cell in the grid can have values 0, 1, or 2 which
    has the following meaning:
    0: Empty cell
    1: Cells have fresh oranges
    2: Cells have rotten oranges
    We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot
    other fresh oranges at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time
    */
    vector<vector<int>>grid{{0, 1, 2}, {0, 1, 2}, {2, 1, 1}};
    int ans = orangesRotting(grid);
    cout << ans << endl;
    return 0;
}
