#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void recurPermute(int ind, vector<int>& nums, vector<vector<int>>& res)
    {
        if (ind == nums.size())
        {
            res.push_back(nums);
            return;
        }
        for (int i = ind; i < nums.size(); i++)
        {
            swap(nums[ind], nums[i]);
            recurPermute(ind + 1, nums, res);
            swap(nums[ind], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        recurPermute(0, nums, res);
        return res;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = sol.permute(nums);

    cout << "All permutations of [1, 2, 3] are:\n";
    for (const auto& permutation : result) {
        cout << "[ ";
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}