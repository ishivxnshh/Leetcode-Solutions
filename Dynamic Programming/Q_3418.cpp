#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int t[501][501][3];

    int solve(vector<vector<int>>& coins, int i, int j, int m, int n, int neu)
    {
        if (i == m - 1 && j == n - 1)
        {
            if (coins[i][j] < 0 && neu > 0)
            {
                return 0;
            }
            return coins[i][j];
        }

        if (i >= m || j >= n) return INT_MIN;

        if (t[i][j][neu] != INT_MIN) return t[i][j][neu];

        // take
        int take = coins[i][j] + max(
            solve(coins, i + 1, j, m, n, neu),
            solve(coins, i, j + 1, m, n, neu)
        );

        // skip
        int skip = INT_MIN;

        if (coins[i][j] < 0 && neu > 0)
        {
            int skipDown = solve(coins, i + 1, j, m, n, neu - 1);
            int skipRight = solve(coins, i, j + 1, m, n, neu - 1);

            skip = max(skipDown, skipRight);
        }

        return t[i][j][neu] = max(take, skip);
    }

    int maximumAmount(vector<vector<int>>& coins)
    {
        int m = coins.size();
        int n = coins[0].size();

        for (int i = 0; i < 501; i++)
        {
            for (int j = 0; j < 501; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    t[i][j][k] = INT_MIN;
                }
            }
        }

        return solve(coins, 0, 0, m, n, 2);
    }
};

int main()
{
    Solution obj;

    // 🔹 Test Case 1
    vector<vector<int>> coins1 =
    {
        {0, 1, -1},
        {1, -2, 3},
        {2, -3, 4}
    };

    cout << "Output 1: " << obj.maximumAmount(coins1) << endl;

    // 🔹 Test Case 2
    vector<vector<int>> coins2 =
    {
        {5, -10, 4},
        {3, -2, 1},
        {1, 2, 10}
    };

    cout << "Output 2: " << obj.maximumAmount(coins2) << endl;

    // 🔹 Test Case 3 (All negative)
    vector<vector<int>> coins3 =
    {
        {-1, -2},
        {-3, -4}
    };

    cout << "Output 3: " << obj.maximumAmount(coins3) << endl;

    return 0;
}