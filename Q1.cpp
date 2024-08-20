#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        // // Brute-force approach
        // for(int i=0;i<nums.size();i++)
        // {
        //     for(int j=0;j<nums.size();j++)
        //     {
        //         if((nums[i]+nums[j]==target) && i!=j)
        //             return {i,j};
        //     }
        // }
        // return {};

        // // Better Approach (using Hashing)
        // unordered_map<int, int> mpp;
        // for(int i=0;i<nums.size();i++)
        // {
        //     int number = nums[i];
        //     int moreNeeded = target - number;
        //     if(mpp.find(moreNeeded) != mpp.end())
        //     {
        //         return{mpp[moreNeeded], i};
        //     }
        //     mpp[number] = i;
        // }
        // return {};

        // //Best Approach if the array is sorted
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int sum = nums[left] + nums[right];
            if (sum == target)
            {
                return {left,right};
            }
            else if (sum < target)
                left++;
            else
                right--;
        }
        return {};
    }
};

int main()
{
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = sol.twoSum(nums1, target1);
    cout << "Test Case 1: Indices of the two numbers that add up to the target are: ";
    for (int i : result1)
    {
        cout << i << " ";
    }
    cout << endl;

    // Test Case 2
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> result2 = sol.twoSum(nums2, target2);
    cout << "Test Case 2: Indices of the two numbers that add up to the target are: ";
    for (int i : result2)
    {
        cout << i << " ";
    }
    cout << endl;

    // Test Case 3
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> result3 = sol.twoSum(nums3, target3);
    cout << "Test Case 3: Indices of the two numbers that add up to the target are: ";
    for (int i : result3)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
