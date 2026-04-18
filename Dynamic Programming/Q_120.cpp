#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp)
    {
        if (i == n - 1) return triangle[n - 1][j];
        if (dp[i][j] != -1) return dp[i][j];

        int down = triangle[i][j] + solve(i + 1, j, n, triangle, dp);
        int diagonal = triangle[i][j] + solve(i + 1, j + 1, n, triangle, dp);

        return dp[i][j] = min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        // Memoization (TLE)
        // TC: O(N^2)
        // SC: O(N^2) + recursion stack O(N)
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solve(0, 0, n, triangle, dp);

        // Tabulation
        // TC: O(N^2)
        // SC: O(N^2)
        // int dp[n][n];
        // for (int j = 0; j < n; j++)
        // {
        //     dp[n - 1][j] = triangle[n - 1][j];
        // }
        // for (int i = n - 2; i >= 0; i--)
        // {
        //     for (int j = 0; j <= i; j++)
        //     {
        //         int d = triangle[i][j] + dp[i + 1][j];
        //         int dg = triangle[i][j] + dp[i + 1][j + 1];
        //         dp[i][j] = min(d, dg);
        //     }
        // }
        // return dp[0][0];

        // Space Optimization
        // TC: O(N^2)
        // SC: O(N)
        vector<int> res(n);

        for (int j = 0; j < n; j++)
        {
            res[j] = triangle[n - 1][j];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            vector<int> curr(n);

            for (int j = 0; j <= i; j++)
            {
                int d = triangle[i][j] + res[j];
                int dg = triangle[i][j] + res[j + 1];

                curr[j] = min(d, dg);
            }

            res = curr;
        }

        return res[0];
    }
};


int main()
{
    Solution obj;

    // Test Case 1
    vector<vector<int>> triangle1 =
    {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    cout << "Output 1: " << obj.minimumTotal(triangle1) << endl;
    // Expected: 11 (2 + 3 + 5 + 1)

    // Test Case 2
    vector<vector<int>> triangle2 =
    {
        {1},
        {2, 3},
        {3, 6, 7},
        {8, 9, 6, 1}
    };

    cout << "Output 2: " << obj.minimumTotal(triangle2) << endl;
    // Expected: 12

    // Test Case 3 (edge case: single row)
    vector<vector<int>> triangle3 =
    {
        {5}
    };

    cout << "Output 3: " << obj.minimumTotal(triangle3) << endl;
    // Expected: 5

    return 0;
}