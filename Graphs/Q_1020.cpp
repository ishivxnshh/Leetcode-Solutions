#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& vis, int delRow[], int delCol[]) {
        vis[r][c] = 1;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < 4; i++) {
            int newRow = r + delRow[i];
            int newCol = c + delCol[i];
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && 
                grid[newRow][newCol] == 1 && !vis[newRow][newCol]) {
                dfs(newRow, newCol, grid, vis, delRow, delCol); 
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        vector<vector<int>> vis(n, vector<int>(m, 0));

        //BFS
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                {
                    if (grid[i][j] == 1)
                    {
                        q.push({i, j});
                        vis[i][j] = 1;
                    }   
                }
            }
        }
        
        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int newRow = r + delRow[i];
                int newCol = c + delCol[i];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1 && !vis[newRow][newCol]) 
                {
                    q.push({newRow, newCol});
                    vis[newRow][newCol] = 1;
                }
            }
        }

        // DFS for boundary 1's
        // for (int j = 0; j < m; j++) {
        //     if (grid[0][j] == 1 && !vis[0][j])
        //         dfs(0, j, grid, vis, delRow, delCol);
        //     if (grid[n - 1][j] == 1 && !vis[n - 1][j])
        //         dfs(n - 1, j, grid, vis, delRow, delCol);
        // }
        // for (int i = 0; i < n; i++) {
        //     if (grid[i][0] == 1 && !vis[i][0])
        //         dfs(i, 0, grid, vis, delRow, delCol);
        //     if (grid[i][m - 1] == 1 && !vis[i][m - 1])
        //         dfs(i, m - 1, grid, vis, delRow, delCol);
        // }

        int count = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1 && !vis[i][j])
                    count++;

        return count;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    int result = sol.numEnclaves(grid);
    cout << "Number of enclaves: " << result << endl;

    return 0;
}