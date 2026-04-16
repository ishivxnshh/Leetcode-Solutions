#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Memoization
    // TC: O(m * n)
    // SC: O(m * n) + recursion stack
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>> & dp)
    {
        if (i == 0 && j == 0) return grid[0][0];
        if (i < 0 || j < 0) return 1e9;

        if (dp[i][j] != -1) return dp[i][j];

        int up = grid[i][j] + solve(i - 1, j, grid, dp);
        int left = grid[i][j] + solve(i, j - 1, grid, dp);

        return dp[i][j] = min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        // memoization
        // TC: O(m * n)
        // SC: O(m * n)
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return solve(m - 1, n - 1, grid, dp);

        // tabulation
        // TC: O(m * n)
        // SC: O(m * n)
        // int dp[m][n];
        // for (int i = 0; i < m; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         if (i == 0 && j == 0) dp[i][j] = grid[0][0];
        //         else
        //         {
        //             int up = 1e9;
        //             int left = 1e9;
        //             if (i > 0) up = grid[i][j] + dp[i - 1][j];
        //             if (j > 0) left = grid[i][j] + dp[i][j - 1];
        //             dp[i][j] = min(up, left);
        //         }
        //     }
        // }
        // return dp[m - 1][n - 1];

        // space optimization
        // TC: O(m * n)
        // SC: O(n)
        vector<int> prev(n, -1);

        for (int i = 0; i < m; i++)
        {
            vector<int> curr(n, -1);

            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0) curr[j] = grid[0][0];
                else
                {
                    int up = 1e9;
                    int left = 1e9;

                    if (i > 0) up = grid[i][j] + prev[j];
                    if (j > 0) left = grid[i][j] + curr[j - 1];

                    curr[j] = min(up, left);
                }
            }
            prev = curr;
        }

        return prev[n - 1];
    }
};

int main()
{
    Solution obj;

    // Test Case 1
    vector<vector<int>> grid1 = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    cout << obj.minPathSum(grid1) << endl;
    // Expected: 7

    // Test Case 2
    vector<vector<int>> grid2 = {
        {1,2,3},
        {4,5,6}
    };
    cout << obj.minPathSum(grid2) << endl;
    // Expected: 12

    // Test Case 3
    vector<vector<int>> grid3 = {
        {5}
    };
    cout << obj.minPathSum(grid3) << endl;
    // Expected: 5

    // Test Case 4
    vector<vector<int>> grid4 = {
        {1,2},
        {1,1}
    };
    cout << obj.minPathSum(grid4) << endl;
    // Expected: 3

    // Test Case 5
    vector<vector<int>> grid5 = {
        {1,9,1},
        {1,1,1},
        {9,1,1}
    };
    cout << obj.minPathSum(grid5) << endl;
    // Expected: 5

    return 0;
}