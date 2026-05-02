#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int r, int c, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp)
    {
        if (c < 0 || c >= n) return 1e9;
        if (r == 0) return matrix[r][c];
        if (dp[r][c] != -1) return dp[r][c];

        int up = matrix[r][c] + solve(r - 1, c, n, matrix, dp);
        int ld = matrix[r][c] + solve(r - 1, c - 1, n, matrix, dp);
        int rd = matrix[r][c] + solve(r - 1, c + 1, n, matrix, dp);

        return dp[r][c] = min({up, ld, rd});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Memoization: TC: O(N^2), SC: O(N^2) + recursion
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // int ans = INT_MAX;
        // for (int c = 0; c < n; c++)
        // {
        //     ans = min(ans, solve(n-1, c, n, matrix, dp));
        // }
        // return ans;

        // Tabulation: TC: O(N^2), SC: O(N^2)
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // for (int i = 0; i < n; i++)
        // {
        //     dp[0][i] = matrix[0][i];
        // }
        // for (int r = 1; r < n; r++)
        // {
        //     for (int c = 0; c < n; c++)
        //     {
        //         int ld = 1e9, rd = 1e9;
        //         int up = matrix[r][c] + dp[r - 1][c];
        //         if (c - 1 >= 0) ld = matrix[r][c] + dp[r - 1][c - 1];
        //         if (c + 1 < n) rd = matrix[r][c] + dp[r - 1][c + 1];

        //         dp[r][c] = min({up, ld, rd});
        //     }
        // }
        // int res = dp[n - 1][0];
        // for (int i = 0; i < n; i++)
        // {
        //     res = min(res, dp[n - 1][i]);
        // }
        // return res;

        // Space Optimization: TC: O(N^2), SC: O(N)
        vector<int> prev(n, -1);

        for (int i = 0; i < n; i++)
        {
            prev[i] = matrix[0][i];
        }

        vector<int> curr(n, -1);

        for (int r = 1; r < n; r++)
        {
            for (int c = 0; c < n; c++)
            {
                int ld = 1e9, rd = 1e9;

                int up = matrix[r][c] + prev[c];

                if (c - 1 >= 0) ld = matrix[r][c] + prev[c - 1];
                if (c + 1 < n) rd = matrix[r][c] + prev[c + 1];

                curr[c] = min({up, ld, rd});
            }

            prev = curr;
        }

        int res = prev[0];

        for (int i = 0; i < n; i++)
        {
            res = min(res, prev[i]);  // FIX
        }

        return res;
    }
};


int main()
{
    Solution obj;

    // Test Case 1
    vector<vector<int>> matrix1 =
    {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };
    cout << "Output 1: " << obj.minFallingPathSum(matrix1) << endl;
    // Expected: 13

    // Test Case 2
    vector<vector<int>> matrix2 =
    {
        {-19, 57},
        {-40, -5}
    };
    cout << "Output 2: " << obj.minFallingPathSum(matrix2) << endl;
    // Expected: -59

    // Test Case 3 (edge case)
    vector<vector<int>> matrix3 =
    {
        {5}
    };
    cout << "Output 3: " << obj.minFallingPathSum(matrix3) << endl;
    // Expected: 5

    return 0;
}