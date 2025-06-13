#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        /*
        Brute-Force Approach
        Time Complexity: O(N^2)
        Space Complexity: O(N)
        */
        // vector<int> res;
        // int n = nums.size();
        // for (int i = 0; i < n; i++)
        // {
        //     int ans = -1;
        //     for (int j = i + 1; j < i + n; j++)
        //     {
        //         if (nums[j % n] > nums[i])
        //         {
        //             ans = nums[j % n];
        //             break;
        //         }
        //     }
        //     res.push_back(ans);
        // }
        // return res;

        // Stack-Based Approach (Optimal)
        // Time Complexity: O(4N)
        // Space Complexity: O(2N + N)

        stack<int> stk;
        vector<int> res;
        for (int i = 2 * nums.size() - 1; i >= 0; i--)
        {
            while (!stk.empty() && stk.top() <= nums[i % nums.size()])
            {
                stk.pop();
            }
            if (i < nums.size())
            {
                if (stk.empty())
                    res.push_back(-1);
                else
                    res.push_back(stk.top());
            }
            stk.push(nums[i % nums.size()]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// Driver Code
int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 1};

    vector<int> result = sol.nextGreaterElements(nums);

    cout << "Next Greater Elements: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
