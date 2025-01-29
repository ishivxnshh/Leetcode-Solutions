#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getSneakyNumbers(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> harr(n, 0);
        vector<int> result;

        for (auto it : nums)
        {
            harr[it]++;
            if (harr[it] == 2)
            {
                result.push_back(it);
            }
        }

        return result;
    }
};

// Driver code
int main()
{
    Solution solution;

    // Sample test case 1
    vector<int> nums1 = {0, 1, 2, 2, 3, 4, 5, 1};
    vector<int> result1 = solution.getSneakyNumbers(nums1);
    cout << "Output for nums = {0, 1, 2, 2, 3, 4, 5, 1}: ";
    for (int num : result1)
    {
        cout << num << " ";
    }
    cout << endl;

    // Sample test case 2
    vector<int> nums2 = {1, 1, 1, 2, 2, 3, 4};
    vector<int> result2 = solution.getSneakyNumbers(nums2);
    cout << "Output for nums = {1, 1, 1, 2, 2, 3, 4}: ";
    for (int num : result2)
    {
        cout << num << " ";
    }
    cout << endl;

    // Sample test case 3
    vector<int> nums3 = {5, 5, 5, 5, 5};
    vector<int> result3 = solution.getSneakyNumbers(nums3);
    cout << "Output for nums = {5, 5, 5, 5, 5}: ";
    for (int num : result3)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}