#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int digitSum(int nums)
    {
        int sum = 0;
        while (nums)
        {
            sum += nums % 10;
            nums /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int> &nums)
    {

        // Brute-Force Approach (tc: nlogn, sc:n)
        // map<int, vector<int>> mpp;
        // int maxi = -1;
        // // Calculate digit sum and group numbers
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     int sum = 0;
        //     int a = nums[i];
        //     while (a > 0)
        //     {
        //         sum += a % 10;
        //         a /= 10;
        //     }
        //     mpp[sum].push_back(nums[i]);
        // }
        // // Find the maximum sum of two numbers with the same digit sum
        // for (auto it : mpp)
        // {
        //     if (it.second.size() > 1)
        //     {
        //         sort(it.second.rbegin(), it.second.rend());
        //         maxi = max(maxi, it.second[0] + it.second[1]);
        //     }
        // }
        // return maxi;

        int arr[82] = {0};
        int maxi = -1;
        for (int num : nums)
        {
            int sum = digitSum(num);
            if (arr[sum] != 0)
            {
                maxi = max(maxi, arr[sum] + num);
            }
            arr[sum] = max(arr[sum], num);
        }
        return maxi;
    }
};

// Driver Code
int main()
{
    Solution sol;

    // Sample Test Cases
    vector<int> nums1 = {51, 71, 17, 42};
    cout << "Test Case 1: " << sol.maximumSum(nums1) << endl; // Expected output: 93 (51 + 42)

    vector<int> nums2 = {10, 12, 19, 14};
    cout << "Test Case 2: " << sol.maximumSum(nums2) << endl; // Expected output: -1 (no valid pairs)

    vector<int> nums3 = {88, 23, 34, 55, 77};
    cout << "Test Case 3: " << sol.maximumSum(nums3) << endl; // Expected output: 165 (88 + 77)

    return 0;
}