#include <bits/stdc++.h>
using namespace std;

// Solution class
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {

        // Brute-Force Appoach(TC: O(n*n),SC: O[1])
        // vector<int> vec;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     if (vec.size() == 0 || vec[0] != nums[i])
        //     {
        //         int cnt = 0;
        //         for (int j = 0; j < nums.size(); j++)
        //         {
        //             if (nums[j] == nums[i])
        //             {
        //                 cnt++;
        //             }
        //         }
        //         if (cnt > (nums.size() / 3))
        //             vec.push_back(nums[i]);
        //     }
        //     if (vec.size() == 2)
        //         break;
        // }
        // return vec;

        // Better Approach(TC: O(n)+O(n)=O(n), SC: O(n))
        // unordered_map<int, int> mpp;
        // vector<int> vec;
        // for (auto it : nums)
        // {
        //     mpp[it]++;
        //     if (mpp[it] > nums.size() / 3 && find(vec.begin(), vec.end(), it) == vec.end())
        //         vec.push_back(it);
        //     if(vec.size()==2)
        //         break;
        // }
        // return vec;

        // Optimal Approach - Boyer Moore Voting Algorithm(TC: O(n), SC: O(1))
        int cnt1 = 0, cnt2 = 0;
        int ele1 = INT_MIN, ele2 = INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(cnt1==0 && nums[i]!=ele2)
            {
                cnt1 = 1;
                ele1 = nums[i];
            }
            else if(cnt2==0 && nums[i]!=ele1)
            {
                cnt2 = 1;
                ele2 = nums[i];
            }
            else if(ele1 == nums[i])
                cnt1++;
            else if(ele2 == nums[i])
                cnt2++;
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        vector<int> vec;
        cnt1 = 0;
        cnt2 = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(ele1==nums[i])
                cnt1++;
            if(ele2==nums[i])
                cnt2++;
        }
        if(cnt1>(int)nums.size()/3)
            vec.push_back(ele1);
        if(cnt2>(int)nums.size()/3)
            vec.push_back(ele2);
        return vec;
    }
};

int main()
{
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {3, 2, 3};
    vector<int> result1 = sol.majorityElement(nums1);
    cout << "Test Case 1: ";
    for (int x : result1)
        cout << x << " ";
    cout << endl;

    // Test Case 2
    vector<int> nums2 = {1, 1, 1, 3, 3, 2, 2, 2};
    vector<int> result2 = sol.majorityElement(nums2);
    cout << "Test Case 2: ";
    for (int x : result2)
        cout << x << " ";
    cout << endl;

    // Test Case 3
    vector<int> nums3 = {1, 2};
    vector<int> result3 = sol.majorityElement(nums3);
    cout << "Test Case 3: ";
    for (int x : result3)
        cout << x << " ";
    cout << endl;

    return 0;
}
