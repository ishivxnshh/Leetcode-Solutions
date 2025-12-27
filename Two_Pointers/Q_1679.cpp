#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxOperations(vector<int>& nums, int k)
    {
        // Time Complexity: O(n log n) due to sorting
        // Space Complexity: O(1) (ignoring input array space)

        sort(nums.begin(), nums.end());

        int ans = 0;
        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            if (nums[left] + nums[right] < k)
            {
                left++;
            }
            else if (nums[left] + nums[right] > k)
            {
                right--;
            }
            else
            {
                ans++;
                left++;
                right--;
            }
        }

        return ans;
    }
};

int main()
{
    // Sample Test Case
    vector<int> nums = {1, 2, 3, 4};
    int k = 5;

    Solution obj;
    int result = obj.maxOperations(nums, k);

    cout << "Maximum Operations: " << result << endl;

    return 0;
}
