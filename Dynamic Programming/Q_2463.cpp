#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int i, int j, vector<int>& robot, vector<int>& factories, vector<vector<long long>>& dp)
    {
        if (i >= robot.size()) return 0;
        if (j >= factories.size()) return 1e12;

        if (dp[i][j] != -1) return dp[i][j];

        long long take = abs(robot[i] - factories[j]) + solve(i + 1, j + 1, robot, factories, dp);
        long long skip = solve(i, j + 1, robot, factories, dp);

        return dp[i][j] = min(take, skip);
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory)
    {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> factories;

        for (auto& fact : factory)
        {
            for (int i = 0; i < fact[1]; i++)
            {
                factories.push_back(fact[0]);
            }
        }

        vector<vector<long long>> dp(robot.size() + 1, vector<long long>(factories.size() + 1, -1));

        return solve(0, 0, robot, factories, dp);
    }
};

int main()
{
    Solution obj;

    // Test Case 1
    vector<int> robot1 = {0, 4, 6};
    vector<vector<int>> factory1 = {{2, 2}, {6, 2}};
    cout << obj.minimumTotalDistance(robot1, factory1) << endl;
    // Expected: 4

    // Test Case 2
    vector<int> robot2 = {1, -1};
    vector<vector<int>> factory2 = {{-2, 1}, {2, 1}};
    cout << obj.minimumTotalDistance(robot2, factory2) << endl;
    // Expected: 2

    // Test Case 3
    vector<int> robot3 = {1, 5, 9};
    vector<vector<int>> factory3 = {{2, 1}, {6, 2}};
    cout << obj.minimumTotalDistance(robot3, factory3) << endl;
    // Expected: 5

    // Test Case 4 (Edge case)
    vector<int> robot4 = {10};
    vector<vector<int>> factory4 = {{0, 1}};
    cout << obj.minimumTotalDistance(robot4, factory4) << endl;
    // Expected: 10

    // Test Case 5
    vector<int> robot5 = {1, 2, 3};
    vector<vector<int>> factory5 = {{2, 3}};
    cout << obj.minimumTotalDistance(robot5, factory5) << endl;
    // Expected: 2

    return 0;
}