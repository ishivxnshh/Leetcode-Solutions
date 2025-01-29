#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        int ans = nums.size();
        while (low <= high)
        {
            int mid = high + (low - high) / 2;
            if (nums[mid] >= target)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    // Call the function and print the result
    int result = solution.searchInsert(nums, target);
    cout << "The index for target " << target << " is: " << result << endl;

    // You can test with other values of target as well
    target = 2;
    result = solution.searchInsert(nums, target);
    cout << "The index for target " << target << " is: " << result << endl;

    target = 7;
    result = solution.searchInsert(nums, target);
    cout << "The index for target " << target << " is: " << result << endl;

    target = 0;
    result = solution.searchInsert(nums, target);
    cout << "The index for target " << target << " is: " << result << endl;

    return 0;
}
