#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        int low = 0;
        int high = 0;

        for (auto it : nums)
        {
            if (it < pivot)
            {
                low++;
            }
            else if (it > pivot)
            {
                high++;
            }
        }

        int mid = low;
        low = 0;
        high = nums.size() - high;

        vector<int> vec(nums.size(), 0);

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < pivot)
            {
                vec[low++] = nums[i];
            }
            else if (nums[i] == pivot)
            {
                vec[mid++] = nums[i];
            }
            else
            {
                vec[high++] = nums[i];
            }
        }

        return vec;
    }
};

// Driver Code
int main()
{
    Solution obj;

    vector<int> nums = {9, 12, 5, 10, 14, 3, 10};
    int pivot = 10;

    vector<int> result = obj.pivotArray(nums, pivot);

    cout << "Rearranged Array: ";

    for (int num : result)
    {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}