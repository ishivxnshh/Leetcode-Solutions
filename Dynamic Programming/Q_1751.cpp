#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> dp;

    // Recursive function to get max value starting from index `idx` with `k` events left
    int solve(vector<vector<int>>& events, int idx, int k)
    {
        // Base cases
        if (idx >= n || k == 0) return 0;

        // If already computed, return memoized value
        if (dp[idx][k] != -1) return dp[idx][k];

        int start = events[idx][0];
        int end = events[idx][1];
        int val = events[idx][2];

        // Option 1: Skip this event
        int skip = solve(events, idx + 1, k);

        // Option 2: Take this event
        // Find next non-overlapping event (events[mid][0] > end)
        int left = idx + 1, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (events[mid][0] > end)
                right = mid - 1;
            else
                left = mid + 1;
        }

        // Now `left` is the index of the next non-overlapping event
        int take = val + solve(events, left, k - 1);

        // Memoize and return the best of take or skip
        return dp[idx][k] = max(skip, take);
    }

    // Main function to start recursion
    int maxValue(vector<vector<int>>& events, int k) {
        // Sort events by start time
        sort(events.begin(), events.end());
        n = events.size();

        // Initialize dp table with -1
        dp = vector<vector<int>>(n, vector<int>(k + 1, -1));

        // Start from index 0 with full `k` picks allowed
        return solve(events, 0, k);
    }
};

// ✅ Test Case with Mini Explanation
int main() {
    Solution sol;

    // Each event is [start, end, value]
    vector<vector<int>> events = {
        {1, 2, 4},   // Event 0: value = 4
        {3, 4, 3},   // Event 1: value = 3
        {2, 3, 10}   // Event 2: value = 10 (overlaps with both above)
    };
    int k = 2;

    // Best pick is only event 2 (value = 10)
    // Picking event 0 + 1 = 4 + 3 = 7 < 10
    cout << "Max value: " << sol.maxValue(events, k) << endl; // Output: 10
    return 0;
}