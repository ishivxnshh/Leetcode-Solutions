#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> findPSE(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> pse(n, -1);
        stack<int> stk;
        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() && nums[stk.top()] >= nums[i])
            {
                stk.pop();
            }
            if (!stk.empty())
            {
                pse[i] = stk.top();
            }

            stk.push(i);
        }
        return pse;
    }

    vector<int> findNSE(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> nse(n, n);
        stack<int> stk;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!stk.empty() && nums[stk.top()] >= nums[i])
            {
                stk.pop();
            }
            if (!stk.empty())
            {
                nse[i] = stk.top();
            }

            stk.push(i);
        }
        return nse;
    }

    int largestRectangleArea(vector<int> &heights)
    {
        // Brute-Force Approach (tc: O(5n), sc: O(4n))
        // vector<int> pse = findPSE(heights);
        // vector<int> nse = findNSE(heights);
        // int maxi = 0;
        // for (int i = 0; i < heights.size(); i++)
        // {
        //     maxi = max(maxi, (nse[i] - pse[i] - 1) * heights[i]);
        // }
        // return maxi;

        // Optimal Approach (tc: O(2n), sc: O(n))
        stack<int> stk;
        int maxi = 0;
        for(int i = 0; i < heights.size(); i++)
        {
            while(!stk.empty() && heights[stk.top()] > heights[i])
            {
                int element = stk.top();
                stk.pop();
                int nse = i;
                int pse = (stk.empty() ? -1 : stk.top());
                maxi = max(maxi, heights[element] * (nse - pse - 1));
            }
            stk.push(i);
        }
        while(!stk.empty())
        {
            int nse = heights.size();
            int element = stk.top();
            stk.pop();
            int pse = (stk.empty() ? -1 : stk.top());
            maxi = max(maxi, heights[element] * (nse - pse - 1));
        }
        return maxi;
    }
};

// Driver Code
int main()
{
    Solution sol;
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    int result = sol.largestRectangleArea(heights);

    cout << "Largest Rectangle Area: " << result << endl;

    return 0;
}
