#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1, premin = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > premin)
                ans = max(ans, nums[i] - premin);
            else
                premin = nums[i];
        }
        return ans;
    }
};

// 🧪 Driver Code
int main() {
    Solution sol;

    // Test cases
    vector<vector<int>> testCases = {
        {7, 1, 5, 4},      // Output: 4
        {9, 4, 3, 2},      // Output: -1
        {1, 5, 2, 10},     // Output: 9
        {1, 1, 1, 1},      // Output: -1
        {2, 4, 1, 7}       // Output: 6
    };

    for (auto& nums : testCases) {
        cout << "Input: ";
        for (int n : nums) cout << n << " ";
        cout << "→ Output: " << sol.maximumDifference(nums) << endl;
    }

    return 0;
}