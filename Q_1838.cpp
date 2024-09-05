#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = 0;
        int res = 0;
        long long total = 0;
        while(r < nums.size())
        {
            total += static_cast<long long>(nums[r]);

            while(static_cast<long long>(nums[r]) * (r - l + 1) > total + k)
            {
                total -= static_cast<long long>(nums[l]);
                l += 1;
            }
            res = max(res,r - l + 1);
            r += 1;
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    //First input
    vector<int> nums1 = {1, 2, 4};
    int k1 = 5;
    int result1 = sol.maxFrequency(nums1, k1);
    cout << "Test case 1 maximum frequency: " << result1 << endl;

    // Second input
    vector<int> nums2 = {1, 4, 8, 13};
    int k2 = 5;
    int result2 = sol.maxFrequency(nums2, k2);
    cout << "Test case 2 maximum frequency: " << result2 << endl;

    // Third input
    vector<int> nums3 = {3, 9, 6};
    int k3 = 2;
    int result3 = sol.maxFrequency(nums3, k3);
    cout << "Test case 3 maximum frequency: " << result3 << endl;

    return 0;
}
