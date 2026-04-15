#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC: O(m * n)
    // SC: O(m * n) + O(m+n) recursion stack
    int solve(int i, int j, vector<vector<int>>& dp)
    {
        if (i == 0 && j == 0) return 1;
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int up = solve(i - 1, j, dp);
        int left = solve(i, j - 1, dp);

        return dp[i][j] = up + left;
    }

    int uniquePaths(int m, int n) {

        // memoization
        // TC: O(m * n)
        // SC: O(m * n) + recursion stack
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return solve(m - 1, n - 1, dp);

        // tabulation
        // TC: O(m * n)
        // SC: O(m * n)
        // int dp[m][n];
        // for (int i = 0; i < m; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         if (i == 0 && j == 0) dp[i][j] = 1;
        //         else
        //         {
        //             int up = 0;
        //             int left = 0;
        //             if (i > 0) up = dp[i - 1][j];
        //             if (j > 0) left = dp[i][j - 1];
        //             dp[i][j] = up + left;
        //         }
        //     }
        // }
        // return dp[m - 1][n - 1];

        // more space optimization
        // TC: O(m * n)
        // SC: O(n)
        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++)
        {
            vector<int> curr(n, 0);

            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0) curr[j] = 1;
                else
                {
                    int up = 0;
                    int left = 0;

                    if (i > 0) up = prev[j];
                    if (j > 0) left = curr[j - 1];

                    curr[j] = up + left;
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

    cout << obj.uniquePaths(3, 7) << endl;  // 28
    cout << obj.uniquePaths(3, 2) << endl;  // 3
    cout << obj.uniquePaths(1, 1) << endl;  // 1
    cout << obj.uniquePaths(2, 2) << endl;  // 2
    cout << obj.uniquePaths(5, 5) << endl;  // 70

    return 0;
}