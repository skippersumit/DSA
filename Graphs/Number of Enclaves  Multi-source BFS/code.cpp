#include <bits/stdc++.h>
using namespace std;

int numberOfEnclaves(vector<vector<int>>&grid) {
    queue<pair<int, int>>q;
    int n = grid.size();
    int m = grid[0].size();
    int vis[n][m] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //boundary cases
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
    }

    int dx[] = { -1, 0, +1, 0};
    int dy[] = {0, +1, +0, -1};

    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        //traverse all the neighbours
        for (int i = 0; i < 4; i++) {
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if (nrow >= 0 and nrow<n and ncol >= 0 and ncol < m and vis[nrow][ncol] == 0 and grid[nrow][ncol] == 1) {
                q.push({nrow, ncol});
                vis[nrow][ncol] = 1;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 && vis[i][j] == 0)cnt++;
        }
    }
    return cnt;
}

int main()
{

    /*
Problem Statement: You are given an N x M binary matrix grid, where 0 represents a sea cell and 1 represents a land cell. A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid. Find the number of land cells in the grid for which we cannot walk off the boundary of the grid in any number of moves.
    */
    vector<vector<int>> grid{
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}};

    int n = grid.size();
    int m = grid[0].size();
    cout<<"Matrix: "<<endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Number Of Enclaves : ";
    cout << numberOfEnclaves(grid) << endl;
    return 0;
}
