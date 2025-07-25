#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> positiveNumsSet;
        for (int num : nums) 
        {
            if (num > 0) 
            {
                positiveNumsSet.emplace(num);
            }
        }
        if (positiveNumsSet.empty()) 
        {
            return *max_element(nums.begin(), nums.end());
        }
        return accumulate(positiveNumsSet.begin(), positiveNumsSet.end(), 0);
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {-1, -2, -3, -4};
    cout << "Max sum (Test 1): " << sol.maxSum(nums1) << endl;

    vector<int> nums2 = {1, 2, 3, 4, 5};
    cout << "Max sum (Test 2): " << sol.maxSum(nums2) << endl;

    vector<int> nums3 = {0, -5, 3, -1, 3};
    cout << "Max sum (Test 3): " << sol.maxSum(nums3) << endl;

    return 0;
}