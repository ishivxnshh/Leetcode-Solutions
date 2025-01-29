#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lowerBound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int ans = nums.size();
        while (left <= right) 
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) 
            {
                ans = mid;
                right = mid - 1;
            } 
            else 
            {
                left = mid + 1;
            }
        }
        return ans;
    }
    int upperBound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int ans = nums.size();
        while (left <= right) 
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) 
            {
                ans = mid;
                right = mid - 1;
            } 
            else 
            {
                left = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {

        // Brute force approach(tc: O(n), sc: O(1))
        // vector<int> ans;
        // int start_index = -1;
        // int end_index = -1;
        // for (int i = 0; i < nums.size(); i++) 
        // {
        //     if (nums[i] == target) 
        //     {
        //         if (start_index == -1) 
        //             start_index = i;
        //         end_index = i;
        //     }
        // }

        // Optimal Approach using lower bound and upper bound (tc: O(2logn), sc: O(1))
        int lb = lowerBound(nums, target);
        if(lb==nums.size() || nums[lb]!=target)
            return {-1, -1};
        return {lb, upperBound(nums, target)-1};

        //Optimal Approach using plain binary search (tc: O(2logn), sc: O(1))
        // int left = 0;
        // int right = nums.size() - 1;
        // int start = -1;
        // int end = -1;
        // while (left <= right)
        // {
        //     int mid = left + (right - left) / 2;
        //     if (nums[mid] == target)
        //     {
        //         start = mid;
        //         right = mid - 1;
        //     }
        //     else if (nums[mid] < target)
        //         left = mid + 1;
        //     else
        //         right = mid - 1;
        // }
        // if (start == -1)
        //     return {-1, -1};
        // left = start;
        // right = nums.size() - 1;
        // while (left <= right)
        // {
        //     int mid = left + (right - left) / 2;
        //     if (nums[mid] == target)
        //     {
        //         end = mid;
        //         left = mid + 1;
        //     }
        //     else if (nums[mid] < target)
        //         left = mid + 1;
        //     else
        //         right = mid - 1;
        // }
        // return {start, end};
    }
};

// Driver code
int main() {
    Solution solution;

    // Sample test case 1
    vector<int> nums1 = {5, 7, 7, 8, 8, 10};
    int target1 = 8;
    vector<int> result1 = solution.searchRange(nums1, target1);
    cout << "Output for nums = {5, 7, 7, 8, 8, 10} and target = 8: ["
         << result1[0] << ", " << result1[1] << "]" << endl;

    // Sample test case 2
    vector<int> nums2 = {5, 7, 7, 8, 8, 10};
    int target2 = 6;
    vector<int> result2 = solution.searchRange(nums2, target2);
    cout << "Output for nums = {5, 7, 7, 8, 8, 10} and target = 6: ["
         << result2[0] << ", " << result2[1] << "]" << endl;

    // Sample test case 3
    vector<int> nums3 = {};
    int target3 = 0;
    vector<int> result3 = solution.searchRange(nums3, target3);
    cout << "Output for nums = {} and target = 0: ["
         << result3[0] << ", " << result3[1] << "]" << endl;

    return 0;
}