#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int repeatedNTimes(vector<int>& nums)
    {
        unordered_map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++)
        {
            mpp[nums[i]]++;
        }

        for (auto [k, v] : mpp)
        {
            if (v == nums.size() / 2)
            {
                return k;
            }
        }

        return -1;
    }
};

int main()
{
    Solution obj;

    // Pre-made test cases (TCS / Interview style)
    vector<vector<int>> testCases = {
        {1, 2, 3, 3},
        {5, 1, 5, 2},
        {9, 4, 9, 9, 9, 9},
        {2, 1, 2, 5, 3, 2}
    };

    for (int i = 0; i < testCases.size(); i++)
    {
        cout << "Test Case " << i + 1 << ": ";
        cout << obj.repeatedNTimes(testCases[i]) << endl;
    }

    return 0;
}
