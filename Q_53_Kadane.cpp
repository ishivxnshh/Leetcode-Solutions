#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        // Brute Force Approach (TC: n^3, SC: 1)
        int max = nums[0];
        for (int i = 0; i < nums.size(); i++) 
        { 
            for (int j = i; j < nums.size(); j++) 
            {
                int sum = 0;
                for (int k = i; k <= j; k++) 
                {
                    sum += nums[k];
                }
                if(sum > max)
                    max = sum;
            }
        }

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

        // Approach to store the starting index and the ending index of the subarray with maximum sum
    //     long long maxi = INT_MIN; // maximum sum
    //     long long sum = 0;
    //     int start = 0;
    //     int ansStart = -1, ansEnd = -1;
    //     for (int i = 0; i < nums.size(); i++) 
    //     {
    //         if (sum == 0) start = i; // starting index
    //         sum += nums[i];
    //         if (sum > maxi) 
    //         {
    //             maxi = sum;
    //             ansStart = start;
    //             ansEnd = i;
    //         }
    //         if (sum < 0) 
    //         {
    //             sum = 0;
    //         }
    //     }
    //     //starting and ending point saved !!
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