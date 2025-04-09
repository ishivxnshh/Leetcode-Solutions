// Time Complexity: O(n)
// Space Complexity: O(n)
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> constructTransformedArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                res[i] = nums[(i + nums[i]) % n];
            }
            else if (nums[i] < 0)
            {
                res[i] = nums[(i + nums[i] % n + n) % n];
            }
            else
            {
                res[i] = nums[i];
            }
        }
        return res;
    }
};

// Driver Code
int main()
{
    Solution sol;
    vector<int> nums = {2, -1, 3, 0, -2};
    vector<int> result = sol.constructTransformedArray(nums);
    
    cout << "Transformed Array: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}