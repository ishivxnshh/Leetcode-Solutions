#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    long long countInterestingSubarrays(vector<int> &nums, int modulo, int k)
    {
        // Time Complexity: O(n)
        // Space Complexity: O(modulo)

        long long count = 0, equals = 0;
        unordered_map<int, long long> mpp;
        mpp[0] = 1; // base case: empty prefix

        for (int num : nums)
        {
            if (num % modulo == k)
            {
                equals++;
            }

            int rem = equals % modulo;
            int needed = (rem - k + modulo) % modulo;

            count += mpp[needed];
            mpp[rem]++;
        }

        return count;
    }
};

// Driver code
int main()
{
    Solution sol;

    vector<int> nums = {3, 1, 4, 1, 5, 9, 2};
    int modulo = 3;
    int k = 1;

    long long result = sol.countInterestingSubarrays(nums, modulo, k);
    cout << "Number of interesting subarrays: " << result << endl;

    return 0;
}