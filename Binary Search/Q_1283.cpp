#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool saDiv(vector<int>& nums, int divisor, int threshold)
    {
        int sum = 0;
        for(auto it: nums)
        {
            sum += (int)ceil((float)it / divisor); // Safe casting to int
        }
        return (sum <= threshold); // Direct comparison
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;  // Set low to 1 to avoid division by 0
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            bool sumAfterDiv = saDiv(nums, mid, threshold);

            if(sumAfterDiv)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};

// Driver Code
int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1, 2, 5, 9};
    int threshold1 = 6;
    cout << "Test Case 1: Smallest Divisor: " << sol.smallestDivisor(nums1, threshold1) << endl;

    // Test Case 2
    vector<int> nums2 = {44, 22, 33, 11, 1};
    int threshold2 = 5;
    cout << "Test Case 2: Smallest Divisor: " << sol.smallestDivisor(nums2, threshold2) << endl;

    // Test Case 3
    vector<int> nums3 = {212, 42, 34, 23, 45, 67};
    int threshold3 = 100;
    cout << "Test Case 3: Smallest Divisor: " << sol.smallestDivisor(nums3, threshold3) << endl;

    return 0;
}
