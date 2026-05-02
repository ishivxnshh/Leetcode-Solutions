#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {

        // TC: O(N)
        // SC: O(1)

        int n = nums.size();

        int sum = 0;   // sum of all elements
        int F = 0;     // initial rotation function F(0)

        // Step 1: Calculate total sum and F(0)
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];          // total sum
            F += i * nums[i];       // F(0) = Σ(i * nums[i])
        }

        int result = F;  // store maximum value

        // Step 2: Use formula to compute F(k) from F(k-1)
        for (int k = 1; k < n; k++)
        {
            // Transition formula:
            // F(k) = F(k-1) + sum - n * nums[n - k]
            F = F + sum - n * nums[n - k];

            // update maximum
            result = max(result, F);
        }

        return result;
    }
};


int main()
{
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {4, 3, 2, 6};
    cout << "Output 1: " << obj.maxRotateFunction(nums1) << endl;
    // Expected: 26

    // Test Case 2 (single element)
    vector<int> nums2 = {100};
    cout << "Output 2: " << obj.maxRotateFunction(nums2) << endl;
    // Expected: 0

    // Test Case 3
    vector<int> nums3 = {1, 2, 3, 4, 5};
    cout << "Output 3: " << obj.maxRotateFunction(nums3) << endl;
    // Expected: 40

    return 0;
}