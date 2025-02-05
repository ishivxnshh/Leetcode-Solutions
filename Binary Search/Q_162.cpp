#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        if (nums[0] > nums[1])
            return 0;
        int n = nums.size();
        if (nums[n - 1] > nums[n - 2])
            return n - 1;

        int left = 1;
        int right = n - 2;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            } else if (nums[mid + 1] > nums[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};

// Driver Code
int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Peak Element Index (Test 1): " << solution.findPeakElement(nums1) << endl;

    // Test Case 2
    vector<int> nums2 = {1, 2, 1, 3, 5, 6, 4};
    cout << "Peak Element Index (Test 2): " << solution.findPeakElement(nums2) << endl;

    // Test Case 3
    vector<int> nums3 = {10, 20, 15, 2, 23, 90, 67};
    cout << "Peak Element Index (Test 3): " << solution.findPeakElement(nums3) << endl;

    return 0;
}