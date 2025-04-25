#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        // Time Complexity: O(n)
        // Space Complexity: O(k)

        unordered_map<int, int> mpp;
        mpp[0] = 1; // to handle subarrays starting from index 0
        int sum = 0;
        int res = 0;

        for (auto num : nums)
        {
            sum += num;
            int rem = sum % k;

            if (rem < 0)
            {
                rem += k; // to handle negative remainders
            }

            if (mpp.find(rem) != mpp.end())
            {
                res += mpp[rem];
            }

            mpp[rem]++;
        }

        return res;
    }
};

// Driver code
int main()
{
    Solution sol;
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;

    int result = sol.subarraysDivByK(nums, k);
    cout << "Number of subarrays divisible by " << k << " is: " << result << endl;

    return 0;
}