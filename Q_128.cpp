#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool linear_search(vector<int> &nums, int a)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == a)
                return true;
        }
        return false;
    }

    int longestConsecutive(vector<int> &nums)
    {

        // Brute - Force Approach(TC : N ^ 2, SC : 1) 
        // if (nums.size() == 0) return 0;
        // int longest = 1;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     int x = nums[i];
        //     int count = 1;
        //     while (linear_search(nums, x + 1) == true)
        //     {
        //         count++;
        //         x++;
        //     }
        //     longest = max(longest, count);
        // }
        // return longest;

        // Better Approach(TC : NlogN, SC : N) 
        // if (nums.size() == 0) return 0;
        // sort(nums.begin(), nums.end());
        // int longest = 1;
        // int cnt_curr = 0;
        // int last_smaller = INT_MIN;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     if (nums[i] == last_smaller + 1)
        //     {
        //         cnt_curr += 1;
        //         last_smaller = nums[i];
        //     }
        //     else if (nums[i] != last_smaller)
        //     {
        //         cnt_curr = 1;
        //         last_smaller = nums[i];
        //     }
        //     longest = max(longest, cnt_curr);
        // }
        // return longest;

        // Optimized Approach(TC : N, SC : N)
        if (nums.size() == 0)
            return 0;
        unordered_set<int> st;
        for (auto it : nums)
        {
            st.insert(it);
        }
        int longest = 1;
        for (auto it : st)
        {
            if (st.find(it - 1) == st.end())
            {
                int cnt = 1;
                int x = it;
                while (st.find(x + 1) != st.end())
                {
                    cnt += 1;
                    x += 1;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};

int main()
{
    Solution sol;

    // Test case 1
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    cout << "Longest consecutive sequence in nums1: " << sol.longestConsecutive(nums1) << endl;
    // Expected output: 4 (sequence is [1, 2, 3, 4])

    // Test case 2
    vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << "Longest consecutive sequence in nums2: " << sol.longestConsecutive(nums2) << endl;
    // Expected output: 9 (sequence is [0, 1, 2, 3, 4, 5, 6, 7, 8])

    return 0;
}
