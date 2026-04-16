#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC: O(n * m)
    // SC: O(n * m) + recursion stack
    int solve(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp)
    {
        if (i >= 0 && j >= 0 && obstacleGrid[i][j] == 1) return 0;
        if (i == 0 && j == 0) return 1;
        if (i < 0 || j < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int up = solve(i - 1, j, obstacleGrid, dp);
        int left = solve(i, j - 1, obstacleGrid, dp);

        return dp[i][j] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        // Memoization
        // TC: O(n * m)
        // SC: O(n * m) + recursion stack
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solve(n - 1, m - 1, obstacleGrid, dp);

        // Tabulation
        // TC: O(n * m)
        // SC: O(n * m)
        // int dp[n][m];
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
        //         else if (i == 0 && j == 0) dp[i][j] = 1;
        //         else
        //         {
        //             int up = 0, left = 0;
        //             if (i > 0) up = dp[i - 1][j];
        //             if (j > 0) left = dp[i][j - 1];
        //             dp[i][j] = up + left;
        //         }
        //     }
        // }
        // return dp[n - 1][m - 1];

        // Space Optimization
        // TC: O(n * m)
        // SC: O(m)
        vector<int> prev(m, 0);

        for (int i = 0; i < n; i++)
        {
            vector<int> curr(m, 0);

            for (int j = 0; j < m; j++)
            {
                if (obstacleGrid[i][j] == 1) curr[j] = 0;
                else if (i == 0 && j == 0) curr[j] = 1;
                else
                {
                    int up = 0, left = 0;

                    if (i > 0) up = prev[j];
                    if (j > 0) left = curr[j - 1];

                    curr[j] = up + left;
                }
            }
            prev = curr;
        }

        return prev[m - 1];
    }
};

int main()
{
    Solution obj;

    // Test Case 1
    vector<vector<int>> grid1 = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };
    cout << obj.uniquePathsWithObstacles(grid1) << endl;
    // Expected: 2

    // Test Case 2
    vector<vector<int>> grid2 = {
        {0,1},
        {0,0}
    };
    cout << obj.uniquePathsWithObstacles(grid2) << endl;
    // Expected: 1

    // Test Case 3 (blocked start)
    vector<vector<int>> grid3 = {
        {1,0}
    };
    cout << obj.uniquePathsWithObstacles(grid3) << endl;
    // Expected: 0

    // Test Case 4 (blocked end)
    vector<vector<int>> grid4 = {
        {0,0},
        {0,1}
    };
    cout << obj.uniquePathsWithObstacles(grid4) << endl;
    // Expected: 0

    // Test Case 5 (no obstacles)
    vector<vector<int>> grid5 = {
        {0,0},
        {0,0}
    };
    cout << obj.uniquePathsWithObstacles(grid5) << endl;
    // Expected: 2

    return 0;
}