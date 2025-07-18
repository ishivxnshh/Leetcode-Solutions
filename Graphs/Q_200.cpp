#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void DFS(int ro, int co, vector<vector<char>>& grid, vector<vector<int>>& vis, int delRow[], int delCol[]) {
        vis[ro][co] = 1;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < 4; i++) {
            int nRow = ro + delRow[i];
            int nCol = co + delCol[i];
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                grid[nRow][nCol] == '1' && !vis[nRow][nCol]) {
                DFS(nRow, nCol, grid, vis, delRow, delCol);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    DFS(i, j, grid, vis, delRow, delCol);
                    count++;
                }
            }
        }

        return count;
    }
};

// ------------------ DRIVER CODE ------------------

int main() {
    Solution obj;

    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    int result = obj.numIslands(grid);
    cout << "Number of Islands: " << result << endl;

    return 0;
}