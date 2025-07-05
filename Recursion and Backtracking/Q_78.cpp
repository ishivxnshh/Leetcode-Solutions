#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> res;

    void generate(int i, vector<int>& nums, vector<int> vec)
    {
        if (i == nums.size())
        {
            res.push_back(vec);
            return;
        }

        // Exclude current element
        generate(i + 1, nums, vec);

        // Include current element
        vec.push_back(nums[i]);
        generate(i + 1, nums, vec);
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        res.clear();
        generate(0, nums, vector<int>());
        return res;
    }
};

// ---------------- Driver Code ----------------
int main()
{
    Solution sol;

    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = sol.subsets(nums);

    cout << "Subsets:" << endl;
    for (const auto& subset : result)
    {
        cout << "[ ";
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}