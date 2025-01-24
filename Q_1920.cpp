#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
};

int main() {
    // Test cases
    vector<vector<int>> testCases = {
        {0, 2, 1, 5, 3, 4}, // Example 1
        {5, 0, 1, 2, 3, 4}, // Example 2
        {4, 3, 2, 1, 0},    // Reverse order
        {0, 1, 2, 3, 4},    // Sorted order
        {3, 1, 2, 0, 4}     // Random order
    };

    Solution sol;
    for (int t = 0; t < testCases.size(); t++) {
        cout << "Test Case " << t + 1 << ": Input: ";
        for (int num : testCases[t]) {
            cout << num << " ";
        }

        vector<int> result = sol.buildArray(testCases[t]);

        cout << "\nOutput: ";
        for (int num : result) {
            cout << num << " ";
        }
        cout << "\n\n";
    }

    return 0;
}
