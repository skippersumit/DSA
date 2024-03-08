#include <bits/stdc++.h>
using namespace std;

void bfs(int r, int c, vector<vector<int>>&vis, vector<vector<char>>&grid) {
    int n = grid.size();
    int m = grid[0].size();
    vis[r][c] = 1;
    queue<pair<int, int>>q;
    q.push({r, c});

    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        //traverse in neighbours
        for (int delRow = -1; delRow <= 1; delRow++) {
            for (int delCol = -1; delCol <= 1; delCol++) {
                int nrow = row + delRow;
                int ncol = col + delCol;

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }

    }
}

int numIslands(vector<vector<char>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>>vis(n, vector<int>(m, 0));
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && grid[i][j] == '1') {
                cnt++;
                bfs(i, j, vis, grid);
            }
        }
    }
    return cnt;
}

int main()
{
    // All Direction connectivity is possible in matrix where all 1's are together
    vector <vector<char>> adj = {{'1', '1', '0', '0', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '1', '0', '0'}, {'0', '0', '0', '1', '1'}};
    cout << numIslands(adj);
    return 0;
}
