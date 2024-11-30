#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {
        for (int i = 1; i <= nums.size(); i++) {
            int greater = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] >= i) {
                    greater++;
                }
            }
            if (greater == i) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {3, 5};
    int expected1 = 2;
    int result1 = sol.specialArray(nums1);
    cout << "Test Case 1: nums = [3, 5]\n";
    cout << "Expected: " << expected1 << ", Got: " << result1 << endl;
    cout << (result1 == expected1 ? "Pass" : "Fail") << endl << endl;

    vector<int> nums2 = {0, 0};
    int expected2 = -1;
    int result2 = sol.specialArray(nums2);
    cout << "Test Case 2: nums = [0, 0]\n";
    cout << "Expected: " << expected2 << ", Got: " << result2 << endl;
    cout << (result2 == expected2 ? "Pass" : "Fail") << endl << endl;

    vector<int> nums3 = {0, 4, 3, 0, 4};
    int expected3 = 3;
    int result3 = sol.specialArray(nums3);
    cout << "Test Case 3: nums = [0, 4, 3, 0, 4]\n";
    cout << "Expected: " << expected3 << ", Got: " << result3 << endl;
    cout << (result3 == expected3 ? "Pass" : "Fail") << endl << endl;

    return 0;
}
