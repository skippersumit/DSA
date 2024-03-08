#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>>&ans, vector<vector<int>>& image, int newColor, int delRow[], int delCol[], int iniColor) {
    // color with new color
    ans[row][col] = newColor;
    int n = image.size();
    int m = image[0].size();
    // there are exactly 4 neighbours
    for (int i = 0; i < 4; i++) {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        // check for valid coordinate
        // then check for same initial color and unvisited pixel
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
            dfs(nrow, ncol, ans, image, newColor, delRow, delCol, iniColor);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int iniColor = image[sr][sc]; // get initial color
    vector<vector<int>> ans = image;
    // delta row and delta column for neighbours
    int delRow[] = { -1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};
    dfs(sr, sc, ans, image, newColor, delRow, delCol, iniColor);
    return ans;
}

int main()
{
    /*
    An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.
    Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor,
    "flood fill" the image. To perform a "flood fill", consider the starting pixel, plus any pixels connected
    4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected
     -directionally to those pixels (also with the same color as the starting pixel), and so on.
    Replace the color of all of the aforementioned pixels with the newColor.
    */

    vector<vector<int>>image{
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    vector<vector<int>> ans = floodFill(image, 1, 1, 2);
    for (auto i : ans) {
        for (auto j : i)
            cout << j << " ";
        cout << "\n";
    }
    return 0;
}
