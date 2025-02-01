#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int min = INT_MAX;
        int min_ind = 0;
        for (int i = 0; i < nums.size(); i++) 
        {
            if (nums[i] < min) 
            {
                min = nums[i];
                min_ind = i;
            }
        }
        return min_ind;
    }

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) 
    {
        for (int i = 0; i < k; i++) 
        {
            int rep_index = findMin(nums);
            nums[rep_index] *= multiplier;
        }
        return nums;
    }
};

// Driver Code
int main() {
    Solution solution;

    // Test Case 1
    vector<int> nums1 = {3, 1, 4, 1, 5};
    int k1 = 2, multiplier1 = 2;
    vector<int> result1 = solution.getFinalState(nums1, k1, multiplier1);
    cout << "Final state after " << k1 << " operations: ";
    for (int num : result1) 
        cout << num << " ";
    cout << endl;

    // Test Case 2
    vector<int> nums2 = {10, 20, 30};
    int k2 = 1, multiplier2 = 5;
    vector<int> result2 = solution.getFinalState(nums2, k2, multiplier2);
    cout << "Final state after " << k2 << " operations: ";
    for (int num : result2) 
        cout << num << " ";
    cout << endl;

    // Test Case 3
    vector<int> nums3 = {2, 2, 2, 2};
    int k3 = 3, multiplier3 = 3;
    vector<int> result3 = solution.getFinalState(nums3, k3, multiplier3);
    cout << "Final state after " << k3 << " operations: ";
    for (int num : result3) 
        cout << num << " ";
    cout << endl;

    return 0;
}
