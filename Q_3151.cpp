#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if ((nums[i] % 2 == 0 && nums[i + 1] % 2 == 0) ||
                (nums[i] % 2 == 1 && nums[i + 1] % 2 == 1)) {
                return false;
            }
        }
        return true;
    }
};

// Driver Code
int main() {
    Solution solution;

    // Test Case 1
    vector<int> nums1 = {1, 2, 3, 4};
    cout << "Is array special? " << (solution.isArraySpecial(nums1) ? "Yes" : "No") << endl;

    // Test Case 2
    vector<int> nums2 = {2, 4, 6, 8};
    cout << "Is array special? " << (solution.isArraySpecial(nums2) ? "Yes" : "No") << endl;

    // Test Case 3
    vector<int> nums3 = {1, 3, 5, 7};
    cout << "Is array special? " << (solution.isArraySpecial(nums3) ? "Yes" : "No") << endl;

    // Test Case 4
    vector<int> nums4 = {1, 2, 1, 2, 1};
    cout << "Is array special? " << (solution.isArraySpecial(nums4) ? "Yes" : "No") << endl;

    return 0;
}
