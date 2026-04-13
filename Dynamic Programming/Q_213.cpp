#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& arr)
    {
        int prev2 = 0;
        int prev = arr[0];

        for (int i = 1; i < arr.size(); i++)
        {
            int take = arr[i];
            if (i > 1) take += prev2;

            int notTake = prev;

            int curr = max(take, notTake);

            prev2 = prev;
            prev = curr;
        }
        return prev;
    }

    int rob(vector<int>& nums)
    {
        int n = nums.size();

        if (n == 1) return nums[0];

        vector<int> temp, temp1;

        for (int i = 0; i < n; i++)
        {
            if (i != 0) temp.push_back(nums[i]);
            if (i != n - 1) temp1.push_back(nums[i]);
        }

        return max(solve(temp), solve(temp1));
    }
};

int main()
{
    Solution obj;

    vector<int> nums1 = {2, 3, 2};
    cout << obj.rob(nums1) << endl;   // Expected: 3

    vector<int> nums2 = {1, 2, 3, 1};
    cout << obj.rob(nums2) << endl;   // Expected: 4

    vector<int> nums3 = {1, 2, 3};
    cout << obj.rob(nums3) << endl;   // Expected: 3

    vector<int> nums4 = {5};
    cout << obj.rob(nums4) << endl;   // Expected: 5

    vector<int> nums5 = {2, 7, 9, 3, 1};
    cout << obj.rob(nums5) << endl;   // Expected: 11

    return 0;
}