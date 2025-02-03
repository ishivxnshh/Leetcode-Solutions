#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestMonotonicSubarray(vector<int>& nums)
    {
        //Brute Force Approach (tc: O(n^2), sc: O(1))
        // int si_max = 1, sd_max = 1;
        // for(int i = 0; i < nums.size()-1; i++)
        // {
        //     int count_i = 1;
        //     int count_d = 1;
        //     for(int j = i; j < nums.size()-1; j++)
        //     {
        //         if(nums[j]<nums[j+1])
        //             count_i++;
        //         else
        //             break;
        //     }
        //     si_max = max(si_max, count_i);

        //     for(int j = i; j < nums.size()-1; j++)
        //     {
        //         if(nums[j]>nums[j+1])
        //             count_d++;
        //         else
        //             break;
        //     }
        //     sd_max = max(sd_max, count_d);
        // }
        // return max(si_max, sd_max);

        //Optimised Approach (tc: O(n), sc: O(1))
        int n = nums.size();
        if (n == 1) 
        {
            return 1;
        }
        int inc = 1, dec = 1, maxLen = 1;
        
        for (int i = 1; i < n; i++) 
        {
            if (nums[i] > nums[i - 1]) 
            {
                inc++;
                dec = 1;
            } 
            else if (nums[i] < nums[i - 1]) 
            {
                dec++;
                inc = 1;
            } 
            else 
            {
                inc = 1;
                dec = 1;
            }
            maxLen = max(maxLen, max(inc, dec));
        }
        
        return maxLen;
    }
};

// Driver Code
int main()
{
    Solution solution;

    // Test Case 1
    vector<int> nums1 = {1, 2, 3, 2, 1};
    cout << "Longest Monotonic Subarray (Test 1): " << solution.longestMonotonicSubarray(nums1) << endl;

    // Test Case 2
    vector<int> nums2 = {10, 9, 8, 7, 6, 5};
    cout << "Longest Monotonic Subarray (Test 2): " << solution.longestMonotonicSubarray(nums2) << endl;

    // Test Case 3
    vector<int> nums3 = {1, 2, 3, 4, 5};
    cout << "Longest Monotonic Subarray (Test 3): " << solution.longestMonotonicSubarray(nums3) << endl;

    return 0;
}
