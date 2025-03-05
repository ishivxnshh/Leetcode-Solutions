#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minSum = 0;
        int maxSum = 0;
        int currentSum = 0;
        for (auto num : nums) {
            currentSum += num;
            minSum = min(minSum, currentSum);
            maxSum = max(maxSum, currentSum);
        }
        return maxSum - minSum;
    }
};

// Driver code
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    int result = sol.maxAbsoluteSum(nums);
    
    cout << "Maximum absolute sum of any subarray: " << result << endl;
    
    return 0;
}