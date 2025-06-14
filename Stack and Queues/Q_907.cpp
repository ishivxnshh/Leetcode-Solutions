#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> findPSEE(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> psee(n, -1);
        stack<int> stk;
        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() && arr[stk.top()] > arr[i])
            {
                stk.pop();
            }
            if (!stk.empty())
                psee[i] = stk.top();
            stk.push(i);
        }
        return psee;
    }

    vector<int> findNSE(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> nse(n, n);
        stack<int> stk;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!stk.empty() && arr[stk.top()] >= arr[i])
            {
                stk.pop();
            }
            if (!stk.empty())
                nse[i] = stk.top();
            stk.push(i);
        }
        return nse;
    }

    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        long long total = 0;
        int mod = 1e9 + 7;
        vector<int> psee = findPSEE(arr);
        vector<int> nse = findNSE(arr);
        for (int i = 0; i < n; i++)
        {
            long long left = i - psee[i];
            long long right = nse[i] - i;
            total = (total + (arr[i] * left % mod) * right % mod) % mod;
        }
        return (int)total;
    }
};

// ---------------- DRIVER CODE ----------------
int main()
{
    Solution sol;

    // Sample input
    vector<int> arr = {3, 1, 2, 4};

    // Function call
    int result = sol.sumSubarrayMins(arr);

    // Output
    cout << "Sum of minimums of all subarrays: " << result << endl;

    return 0;
}