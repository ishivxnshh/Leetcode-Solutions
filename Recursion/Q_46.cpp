#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void recurPermute(vector<int> temp, vector<int>& nums, vector<vector<int>>& res, int* fq)
    {
        if (temp.size() == nums.size())
        {
            res.push_back(temp);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!fq[i])
            {
                temp.push_back(nums[i]);
                fq[i] = 1;
                recurPermute(temp, nums, res, fq);
                temp.pop_back();
                fq[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> res;
        int* fq = new int[nums.size()]();
        recurPermute(vector<int>(), nums, res, fq);
        delete[] fq;
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = sol.permute(nums);

    cout << "Permutations:\n";
    for (const auto& perm : result)
    {
        for (int val : perm)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}