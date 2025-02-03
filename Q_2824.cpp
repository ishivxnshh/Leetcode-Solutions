#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    int countPairs(vector<int>& nums, int target) 
    {
        // Brute Force Approach (tc: O(n^2), sc: O(1))
        // int count = 0;
        // for(int i = 0; i < nums.size() - 1; i++)
        // {
        //     for(int j = i + 1; j < nums.size(); j++)
        //     {
        //         if(nums[i] + nums[j] < target)
        //             count++;
        //     }
        // }
        // return count;

        // Optimized Approach (tc: O(nlogn)+O(n)=O(nlogn), sc: O(n))
        sort(nums.begin(), nums.end());  // Sort the array
        int count = 0, left = 0, right = nums.size() - 1;
        while (left < right) 
        {
            if (nums[left] + nums[right] < target) 
            {
                count += (right - left);
                left++;
            } 
            else 
            {
                right--;
            }
        }
        return count;

    }
};

// Driver Code
int main() 
{
    Solution solution;

    // Test Case 1
    vector<int> nums1 = {-1, 1, 2, 3, 1};
    int target1 = 2;
    cout << "Count of pairs: " << solution.countPairs(nums1, target1) << endl;

    // Test Case 2
    vector<int> nums2 = {-6, 2, 5, -2, -7, -1, 3};
    int target2 = -2;
    cout << "Count of pairs: " << solution.countPairs(nums2, target2) << endl;

    return 0;
}
