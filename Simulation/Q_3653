#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    const int MOD = 1e9 + 7;

    void apply(vector<int>& nums, int l, int r, int k, int v)
    {
        // TC: O((r - l) / k)
        // SC: O(1)

        for (int i = l; i <= r; i += k)
        {
            nums[i] = (1LL * nums[i] * v) % MOD;
        }
    }
    
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) 
    {
        // TC: O(Q * (range / k)) + O(N)
        // Worst case: O(Q * N)
        // SC: O(1)

        for (int i = 0; i < queries.size(); i++)
        {
            apply(nums, queries[i][0], queries[i][1], queries[i][2], queries[i][3]);
        }

        int res = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            res ^= nums[i];
        }

        return res;
    }
};

int main()
{
    // TC: O(N + Q * (range / k))
    // SC: O(1)

    Solution obj;

    vector<int> nums = {1, 2, 3, 4, 5};

    vector<vector<int>> queries = 
    {
        {0, 4, 1, 2},  // multiply all by 2
        {1, 3, 2, 3}   // multiply indices 1 and 3 by 3
    };

    int result = obj.xorAfterQueries(nums, queries);

    cout << "Result XOR: " << result << endl;

    return 0;
}
