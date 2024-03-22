#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>>&grid, vector<vector<int>>&vis,
         vector<pair<int, int>>&vec, int row0, int col0) {
    int n = grid.size();
    int m = grid[0].size();
    vis[row][col] = 1;
    vec.push_back({row - row0, col - col0});
    int dx[] = { -1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};

    for (int i = 0; i < 4; i++) {
        int nrow = row + dx[i];
        int ncol = col + dy[i];
        if (nrow >= 0 and nrow<n and ncol >= 0 and ncol < m
                and !vis[nrow][ncol] and grid[nrow][ncol] == 1) {
            dfs(nrow, ncol, grid, vis, vec, row0, col0);
        }
    }
}

int countDistinctIslands(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    set<vector<pair<int, int>>>st;
    vector<vector<int>>vis(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] and grid[i][j] == 1) {
                vector<pair<int, int>>vec;
                dfs(i, j, grid, vis, vec, i, j);
                st.insert(vec);
            }
        }
    }

    return st.size();
}

int main()
{

    /*
Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected)
    */
    vector<vector<int>> grid{{1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1}};
    int n = grid.size();
    int m = grid[0].size();
    cout << "Matrix: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Number Of distinct islands : ";
    cout << countDistinctIslands(grid) << endl;

    grid = {{1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {1, 1, 0, 1, 1}
    };

    n = grid.size();
    m = grid[0].size();
    cout << "Matrix: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Number Of distinct islands : ";
    cout << countDistinctIslands(grid) << endl;

    return 0;
}
