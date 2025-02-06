#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int, int> mpp;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
                mpp[nums[i] * nums[j]]++;           
        }
        int count = 0;
        for(auto m : mpp)
        {
            int x = m.second;
            int comb = (x * (x - 1)) / 2;
            count += comb * 8;
        }
        return count;
    }
};

// Driver Code
int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {2, 3, 4, 6};
    cout << "Test Case 1: " << sol.tupleSameProduct(nums1) << endl; // Expected Output: 8

    // Test Case 2
    vector<int> nums2 = {1, 2, 4, 5, 10};
    cout << "Test Case 2: " << sol.tupleSameProduct(nums2) << endl; // Expected Output: 16

    // Test Case 3
    vector<int> nums3 = {2, 3, 5, 7};
    cout << "Test Case 3: " << sol.tupleSameProduct(nums3) << endl; // Expected Output: 0

    return 0;
}
