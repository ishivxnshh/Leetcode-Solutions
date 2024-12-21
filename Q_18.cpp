#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{

    // Brute Force(tc: 𝑂(𝑛^4.log𝑛), sc: 𝑂(𝑛^4)) (tle: 288/294 passed)
    // if (nums.size() < 4) return {};
    // set<vector<int>> st;
    // for (int i = 0; i < nums.size() - 3; i++)
    // {
    //     for (int j = i + 1; j < nums.size() - 2; j++)
    //     {
    //         for (int k = j + 1; k < nums.size() - 1; k++)
    //         {
    //             for (int l = k + 1; l < nums.size(); l++)
    //             {
    //                 long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
    //                 if (sum == target)
    //                 {
    //                     vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
    //                     sort(temp.begin(), temp.end());
    //                     st.insert(temp);
    //                 }
    //             }
    //         }
    //     }
    // }
    // vector<vector<int>> result(st.begin(), st.end());
    // return result;

    // Better Approach(tc: 𝑂(𝑛^3.log𝑛), sc: 𝑂(𝑛^3))
    // if (nums.size() < 4)
    //     return {};
    // set<vector<int>> st1;
    // for (int i = 0; i < nums.size() - 3; i++)
    // {
    //     for (int j = i + 1; j < nums.size() - 2; j++)
    //     {
    //         set<long long> st;
    //         for (int k = j + 1; k < nums.size(); k++)
    //         {
    //             long long sum = (long long)nums[i] + nums[j] + nums[k];
    //             long long fourth = target - (sum);
    //             if (st.find(fourth) != st.end())
    //             {
    //                 vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
    //                 sort(temp.begin(), temp.end());
    //                 st1.insert(temp);
    //             }
    //             st.insert(nums[k]);
    //         }
    //     }
    // }
    // vector<vector<int>> result(st1.begin(), st1.end());
    // return result;

    // Optimized Approach(tc: 𝑂(nlog𝑛 + 𝑛^3), sc: 𝑂(k))
    if (nums.size() < 4)
        return {};
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    for (int i = 0; i < nums.size() - 3; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < nums.size() - 2; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            int k = j + 1, l = nums.size() - 1;
            while (k < l)
            {
                long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                if (sum < target)
                    k++;
                else if (sum > target)
                    l--;
                else
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    result.push_back(temp);
                    k++;
                    l--;
                    while (k < l && nums[k] == nums[k - 1])
                        k++;
                    while (k < l && nums[l] == nums[l + 1])
                        l--;
                }
            }
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> result = fourSum(nums, target);

    cout << "Quadruplets that sum to " << target << " are:" << endl;
    for (const auto &quad : result)
    {
        for (int num : quad)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}