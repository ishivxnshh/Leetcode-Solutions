#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    int maxAdjacentDistance(vector<int>& nums)
    {
        int maxi = abs(nums[nums.size() - 1] - nums[0]);
        for (size_t i = 1; i < nums.size(); i++)
        {
            maxi = max(maxi, abs(nums[i] - nums[i - 1]));
        }
        return maxi;
    }
};

// Driver code
int main()
{
    Solution obj;

    vector<int> nums = {4, 8, 6, 2, 9}; // Sample input

    int result = obj.maxAdjacentDistance(nums);

    cout << "Maximum Adjacent Distance: " << result << endl;

    return 0;
}