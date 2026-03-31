#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int solve(int ind, vector<int> &dp)
    {
        if (ind <= 1) return 1;
        if (dp[ind] != -1) return dp[ind];
        return dp[ind] = solve(ind - 1, dp) + solve(ind - 2, dp);
    }

    int climbStairs(int n) {
        // if (n <= 2)
        //     return n;
        // int first = 1;
        // int second = 2;
        // for (int i = 3; i <= n; i++) {
        //     int third = first + second;
        //     first = second;
        //     second = third;
        // }
        // return second;

        // Using DP
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};

// Driver Code
int main() {
    Solution sol;

    // Test Cases
    cout << "Ways to climb 1 step: " << sol.climbStairs(1) << endl;  // Expected Output: 1
    cout << "Ways to climb 2 steps: " << sol.climbStairs(2) << endl; // Expected Output: 2
    cout << "Ways to climb 3 steps: " << sol.climbStairs(3) << endl; // Expected Output: 3
    cout << "Ways to climb 4 steps: " << sol.climbStairs(4) << endl; // Expected Output: 5
    cout << "Ways to climb 5 steps: " << sol.climbStairs(5) << endl; // Expected Output: 8

    return 0;
}
