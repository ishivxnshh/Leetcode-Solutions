#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {

        // vector< vector<int>> res;
        // unordered_map<int, int> mpp;
        // int a = 0;
        // for(int i=0;i<nums.size();i++)
        // {
        //     mpp[nums[i]]++;
        //     if(mpp[nums[i]]>a)
        //     {
        //         a = mpp[nums[i]];
        //         res.push_back({});
        //     }
        //     int j = mpp[nums[i]];
        //     res[j-1].push_back(nums[i]);
        // }
        // return res;

        // More efficient way to solve the problem
        unordered_map<int, int> mpp;
        vector<vector<int>> res;
        for (int num : nums)
        {
            int freq = mpp[num]++;
            if (res.size() <= freq)
            {
                res.push_back({});
            }

            res[freq].push_back(num);
        }
        return res;
    }
};

// Driver Code
int main()
{
    Solution solution;

    // Sample Test Case 1
    vector<int> nums1 = {1, 3, 4, 1, 2, 3, 1};
    vector<vector<int>> result1 = solution.findMatrix(nums1);
    cout << "Output for nums = {1, 3, 4, 1, 2, 3, 1}:\n";
    for (const auto &row : result1)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Sample Test Case 2
    vector<int> nums2 = {5, 5, 5, 5};
    vector<vector<int>> result2 = solution.findMatrix(nums2);
    cout << "Output for nums = {5, 5, 5, 5}:\n";
    for (const auto &row : result2)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Sample Test Case 3
    vector<int> nums3 = {2, 1, 2, 1, 2, 1};
    vector<vector<int>> result3 = solution.findMatrix(nums3);
    cout << "Output for nums = {2, 1, 2, 1, 2, 1}:\n";
    for (const auto &row : result3)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}