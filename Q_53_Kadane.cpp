#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        // Brute Force Approach (TC: n^3, SC: 1)
        // int max = nums[0];
        // for(int i = 0; i < nums.size(); i++) {
        //     int sum = 0;
        //     for(int j = i; j < nums.size(); j++) {
        //         sum += nums[j];
        //         if(sum > max)
        //             max = sum;
        //     }
        // }
        // return max;

        // Better Approach (TC: n^2, SC: 1)
        // int max = nums[0];
        // for(int i = 0; i < nums.size(); i++) {
        //     int sum = 0;
        //     for(int j = i; j < nums.size(); j++) {
        //         sum += nums[j];
        //         if(sum > max)
        //             max = sum;
        //     }
        // }
        // return max;

        // Optimal Approach (TC: n, SC: 1)
        // int sum = 0;
        // int maxi = nums[0];
        // for(auto ele:nums)
        // {
        //     sum+=ele;
        //     maxi = max(sum,maxi);
        //     if(sum<0)
        //         sum = 0;
        // }
        // return maxi;

        // Pri
    }
};

// Driver code
int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Test case 1 - Maximum subarray sum: " << solution.maxSubArray(nums1) << endl;

    // Test case 2
    vector<int> nums2 = {1};
    cout << "Test case 2 - Maximum subarray sum: " << solution.maxSubArray(nums2) << endl;

    // Test case 3
    vector<int> nums3 = {5, 4, -1, 7, 8};
    cout << "Test case 3 - Maximum subarray sum: " << solution.maxSubArray(nums3) << endl;

    return 0;
}