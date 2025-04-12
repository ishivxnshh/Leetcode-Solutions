#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void generateKro(int ind, vector<int>& nums, vector<int> temp, vector<vector<int>>& res)
    {
        res.push_back(temp);
        for (int i = ind; i < nums.size(); i++)
        {
            if (i > ind && nums[i] == nums[i - 1])
                continue;
            temp.push_back(nums[i]);
            generateKro(i + 1, nums, temp, res);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        generateKro(0, nums, vector<int>(), res);
        return res;
    }
};

// Driver Code
int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 2};

    vector<vector<int>> result = sol.subsetsWithDup(nums);

    cout << "Subsets with duplicates:\n";
    for (const auto& subset : result)
    {
        cout << "[ ";
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}