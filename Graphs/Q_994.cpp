#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Time Complexity: O(n * m)
// Space Complexity: O(n * m)

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(); // number of rows
        int m = grid[0].size(); // number of columns
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        int countFresh = 0;

        // Step 1: Push all initially rotten oranges into queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                } else if (grid[i][j] == 1) {
                    countFresh++;
                }
            }
        }

        int count = 0;
        int time = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        // Step 2: BFS traversal to rot adjacent fresh oranges
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                    count++;
                }
            }
        }

        return count == countFresh ? time : -1;
    }
};

// Driver Code
int main() {
    Solution obj;

    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    int result = obj.orangesRotting(grid);
    cout << "Minimum time to rot all oranges: " << result << endl;

    return 0;
}