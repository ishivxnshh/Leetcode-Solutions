#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) 
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) 
            {
                return true;
            }
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) 
            {
                left++;
                right--;
                continue;
            }
            if (nums[left] <= nums[mid]) 
            {
                if (nums[left] <= target && target < nums[mid]) 
                {
                    right = mid - 1;
                } else 
                {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[right]) 
                {
                    left = mid + 1;
                } else 
                {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution solution;

    // Test Case 1
    vector<int> nums1 = {2, 5, 6, 0, 0, 1, 2};
    int target1 = 0;
    cout << "Test Case 1: " << (solution.search(nums1, target1) ? "Found" : "Not Found") << endl;

    // Test Case 2
    vector<int> nums2 = {2, 5, 6, 0, 0, 1, 2};
    int target2 = 3;
    cout << "Test Case 2: " << (solution.search(nums2, target2) ? "Found" : "Not Found") << endl;

    // Test Case 3
    vector<int> nums3 = {1, 1, 3, 1};
    int target3 = 3;
    cout << "Test Case 3: " << (solution.search(nums3, target3) ? "Found" : "Not Found") << endl;

    // Test Case 4
    vector<int> nums4 = {1};
    int target4 = 0;
    cout << "Test Case 4: " << (solution.search(nums4, target4) ? "Found" : "Not Found") << endl;

    return 0;
}
