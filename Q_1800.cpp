#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxi = 0;
        int sum = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<=nums[i-1])
            {
                maxi = max(maxi, sum);
                sum = 0;            
            }
            sum+=nums[i];            
        }
        return max(maxi, sum);
    }
};

// Driver Code
int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> nums1 = {10, 20, 30, 5, 10, 50};
    cout << "Max Ascending Sum (Test 1): " << solution.maxAscendingSum(nums1) << endl;

    // Test Case 2
    vector<int> nums2 = {3, 6, 10, 15, 1, 2, 3};
    cout << "Max Ascending Sum (Test 2): " << solution.maxAscendingSum(nums2) << endl;

    // Test Case 3
    vector<int> nums3 = {100, 200, 300, 400};
    cout << "Max Ascending Sum (Test 3): " << solution.maxAscendingSum(nums3) << endl;

    return 0;
}
