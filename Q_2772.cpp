#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        
        // Brute-Force Approach(2 tcs failing, TC:O(n * k), SC:O(1))
        for (int i = 0; i <= nums.size() - k; i++) {
            if (nums[i] > 0) {
                int a = nums[i];
                for (int j = i; j < i + k; j++) {
                    nums[j] -= a;
                    if (nums[j] < 0) return false;
                }
            }
        }
        for (int num : nums) {
            if (num != 0) return false;
        }
        return true;
    }
};

int main() {
    Solution solution;

    // Test Case 1
    vector<int> nums1 = {2, 2, 3, 1, 1, 0};
    int k1 = 3;
    cout << (solution.checkArray(nums1, k1) ? "true" : "false") << endl;

    // Test Case 2
    vector<int> nums2 = {1, 3, 1, 1};
    int k2 = 2;
    cout << (solution.checkArray(nums2, k2) ? "true" : "false") << endl;

    return 0;
}
