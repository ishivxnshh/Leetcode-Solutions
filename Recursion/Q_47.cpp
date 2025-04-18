#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void recurPermute(vector<int> temp, vector<int>& nums, vector<vector<int>>& res, int *fq)
    {
        if(temp.size() == nums.size())
        {
            res.push_back(temp);
            return;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(fq[i] == 0)
            {
                if(i > 0 && nums[i] == nums[i - 1] && fq[i - 1] == 0)
                {
                    continue;
                }
                temp.push_back(nums[i]);
                fq[i] = 1;
                recurPermute(temp, nums, res, fq);
                temp.pop_back();
                fq[i] = 0;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int *fq = new int[nums.size()]();
        recurPermute(vector<int>(), nums, res, fq);
        delete[] fq;
        return res;
    }
};

// 🧪 Driver code
int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 2};

    vector<vector<int>> result = sol.permuteUnique(nums);

    cout << "Unique permutations:\n";
    for(const auto& perm : result)
    {
        for(int num : perm)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
