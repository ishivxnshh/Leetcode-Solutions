#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        sort(nums.rbegin(), nums.rend()); // Sorting in descending order
        int count = 0;
        while (nums.size() > 0)
        {
            if (nums.back() >= k)
                break;
            count++;
            nums.pop_back();
        }
        return count;
    }
};

// **Driver Code**
int main()
{
    Solution sol;

    // **Sample Test Case 1**
    vector<int> nums1 = {3, 1, 5, 8, 2};
    int k1 = 4;
    cout << "Minimum Operations: " << sol.minOperations(nums1, k1) << endl;
    // Expected Output: 2

    // **Sample Test Case 2**
    vector<int> nums2 = {10, 15, 7, 3, 9};
    int k2 = 8;
    cout << "Minimum Operations: " << sol.minOperations(nums2, k2) << endl;
    // Expected Output: 1

    return 0;
}
