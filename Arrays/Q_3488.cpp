#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC: O(n + q log n)
    // SC: O(n)
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {

        int n = nums.size();

        unordered_map<int, vector<int>> dict; // value -> sorted indices

        // TC: O(n)
        for (int i = 0; i < n; i++)
        {
            dict[nums[i]].push_back(i);
        }

        vector<int> result;

        // TC: O(q log n)
        for (int query : queries)
        {
            int val = nums[query];
            auto& indices = dict[val];

            int sz = indices.size();

            if (sz == 1)
            {
                result.push_back(-1);
                continue;
            }

            int pos = lower_bound(indices.begin(), indices.end(), query) - indices.begin();

            int res = INT_MAX;
            
            // RIGHT NEIGHBOUR
            int right = indices[(pos + 1) % sz];
            int d = abs(query - right);
            res = min(res, min(d, n - d));

            // LEFT NEIGHBOUR
            int left = indices[(pos - 1 + sz) % sz];
            d = abs(query - left);
            res = min(res, min(d, n - d));

            result.push_back(res);
        }

        return result;
    }
};

int main()
{
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {1,3,1,4,1,3};
    vector<int> queries1 = {0,1,2,3};
    vector<int> res1 = obj.solveQueries(nums1, queries1);
    for (int x : res1) cout << x << " ";
    cout << endl;
    // Expected: 2 4 2 -1

    // Test Case 2
    vector<int> nums2 = {5,5,5};
    vector<int> queries2 = {0,1,2};
    vector<int> res2 = obj.solveQueries(nums2, queries2);
    for (int x : res2) cout << x << " ";
    cout << endl;
    // Expected: 1 1 1

    // Test Case 3
    vector<int> nums3 = {1,2,3,4};
    vector<int> queries3 = {0,1,2,3};
    vector<int> res3 = obj.solveQueries(nums3, queries3);
    for (int x : res3) cout << x << " ";
    cout << endl;
    // Expected: -1 -1 -1 -1

    return 0;
}