#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
            return -1;

        if (n == 1 && m == 1)
            return 1;

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 1;

        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});

        vector<int> dr = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dc = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty()) {
            auto [dis, pos] = q.front();
            q.pop();

            int r = pos.first;
            int c = pos.second;

            for (int d = 0; d < 8; d++) {
                int newR = r + dr[d];
                int newC = c + dc[d];

                if (newR >= 0 && newR < n && newC >= 0 && newC < m &&
                    grid[newR][newC] == 0 && dis + 1 < dist[newR][newC]) {
                    
                    if (newR == n - 1 && newC == m - 1)
                        return dis + 1;

                    dist[newR][newC] = dis + 1;
                    q.push({dis + 1, {newR, newC}});
                }
            }
        }

        return -1;
    }
};

// 🔽 Driver Code
int main() {
    Solution obj;

    // Sample input 1
    vector<vector<int>> grid1 = {{0}};
    cout << "Output for grid1: " << obj.shortestPathBinaryMatrix(grid1) << endl;

    // Sample input 2
    vector<vector<int>> grid2 = {
        {0, 1},
        {1, 0}
    };
    cout << "Output for grid2: " << obj.shortestPathBinaryMatrix(grid2) << endl;

    // Sample input 3
    vector<vector<int>> grid3 = {
        {0, 0, 0},
        {1, 1, 0},
        {1, 1, 0}
    };
    cout << "Output for grid3: " << obj.shortestPathBinaryMatrix(grid3) << endl;

    return 0;
}