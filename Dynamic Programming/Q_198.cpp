#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int i, vector<int>& nums, vector<int>& dp)
    {
        if (i == 0) return nums[0];
        if (i < 0) return 0;
        if (dp[i] != -1) return dp[i];

        int take = nums[i] + solve(i - 2, nums, dp);
        int not_take = solve(i - 1, nums, dp);

        return dp[i] = max(take, not_take);
    }

    int rob(vector<int>& nums)
    {
        int n = nums.size();

        // vector<int> dp(n, -1);
        // return solve(n - 1, nums, dp);

        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int prev = nums[0];
        int prev2 = 0;

        for (int i = 1; i < n; i++)
        {
            int take = nums[i];
            if (i > 1)
            {
                take += prev2;
            }

            int notTake = prev;

            int curr = max(take, notTake);

            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};

int main()
{
    Solution obj;

    // 🔹 Test Case 1
    vector<int> t1 = {1, 2, 3, 1};
    cout << "Test 1 Output: " << obj.rob(t1) << endl;

    // 🔹 Test Case 2
    vector<int> t2 = {2, 7, 9, 3, 1};
    cout << "Test 2 Output: " << obj.rob(t2) << endl;

    // 🔹 Test Case 3
    vector<int> t3 = {2, 1, 1, 2};
    cout << "Test 3 Output: " << obj.rob(t3) << endl;

    // 🔹 Test Case 4 (edge)
    vector<int> t4 = {5};
    cout << "Test 4 Output: " << obj.rob(t4) << endl;

    // 🔹 Test Case 5
    vector<int> t5 = {10, 5, 15, 20, 2, 30};
    cout << "Test 5 Output: " << obj.rob(t5) << endl;

    return 0;
}
