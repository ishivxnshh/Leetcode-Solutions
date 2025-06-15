#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:

    vector<int> findPGEE(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> pgee(n, -1);
        stack<int> stk;
        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() && nums[stk.top()] < nums[i])
            {
                stk.pop();
            }
            if (!stk.empty()) pgee[i] = stk.top();
            stk.push(i);
        }
        return pgee;
    }

    vector<int> findNGE(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> nge(n, n);
        stack<int> stk;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!stk.empty() && nums[stk.top()] <= nums[i])
            {
                stk.pop();
            }
            if (!stk.empty()) nge[i] = stk.top();
            stk.push(i);
        }
        return nge;
    }

    vector<int> findPSEE(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> psee(n, -1);
        stack<int> stk;
        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() && nums[stk.top()] > nums[i])
            {
                stk.pop();
            }
            if (!stk.empty()) psee[i] = stk.top();
            stk.push(i);
        }
        return psee;
    }

    vector<int> findNSE(vector<int>& nums)
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
            if (!stk.empty()) nse[i] = stk.top();
            stk.push(i);
        }
        return nse;
    }

    long long maxSubarraySum(vector<int>& nums)
    {
        vector<int> pgee = findPGEE(nums);
        vector<int> nge = findNGE(nums);
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            long long left = i - pgee[i];
            long long right = nge[i] - i;
            sum += (left * right * nums[i]);
        }
        return sum;
    }

    long long minSubarraySum(vector<int>& nums)
    {
        vector<int> psee = findPSEE(nums);
        vector<int> nse = findNSE(nums);
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            long long left = i - psee[i];
            long long right = nse[i] - i;
            sum += (left * right * nums[i]);
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums)
    {
        return (maxSubarraySum(nums) - minSubarraySum(nums));
    }
};

// ==================== DRIVER CODE ====================
int main()
{
    Solution sol;

    vector<int> nums = {1, 2, 3};

    long long result = sol.subArrayRanges(nums);

    cout << "Sum of Subarray Ranges: " << result << endl;

    return 0;
}