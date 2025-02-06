// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> ans(nums.size());
        int leftSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = leftSum;
            leftSum += nums[i];
        }
        int rightSum = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            ans[i] = abs(ans[i] - rightSum);
            rightSum += nums[i];
        }
        return ans;
    }
};

// Driver Code
int main() {
    Solution sol;
    
    vector<int> nums1 = {10, 4, 8, 3};
    vector<int> result1 = sol.leftRightDifference(nums1);
    cout << "Test Case 1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;
    
    vector<int> nums2 = {1, 2, 3, 4, 5};
    vector<int> result2 = sol.leftRightDifference(nums2);
    cout << "Test Case 2: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;
    
    vector<int> nums3 = {5, 5, 5, 5};
    vector<int> result3 = sol.leftRightDifference(nums3);
    cout << "Test Case 3: ";
    for (int num : result3) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
