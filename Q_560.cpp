#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        // Brute Force Approach (TLE), (TC: n^3, SC: 1)
        // int count = 0;
        // for (int i = 0; i < nums.size(); i++) {
        //     for (int j = i; j < nums.size(); j++) {
        //         int sum = 0;
        //         for (int l = i; l <= j; l++) {
        //             sum += nums[l];
        //         }
        //         if (sum == k)
        //             count++;
        //     }
        // }
        // return count;

        // Better Approach (TC: n^2, SC: 1)
        // int count = 0;
        // for(int i = 0; i < nums.size(); i++)
        // {
        //     int sum = 0;
        //     for(int j = i; j < nums.size(); j++)
        //     {
        //         sum+=nums[j];
        //         if(sum==k)
        //             count++;
        //     }
        // }
        // return count;

        //Optimized Approach (TC:N, SC:N)
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int prefixSum = 0;
        int count = 0;
        for(int i=0; i<nums.size(); i++)
        {
            prefixSum+=nums[i];
            int remove = prefixSum - k;
            count+=mpp[remove];
            mpp[prefixSum]+=1; 
        }
        return count;

    }
};

int main() {
    Solution solution;
    
    // Example 1: A test case
    vector<int> nums = {1, 2, 3};
    int k = 3;
    cout << "Number of subarrays with sum " << k << ": " << solution.subarraySum(nums, k) << endl;

    // Example 2: Another test case
    vector<int> nums2 = {1, 1, 1};
    int k2 = 2;
    cout << "Number of subarrays with sum " << k2 << ": " << solution.subarraySum(nums2, k2) << endl;

    return 0;
}