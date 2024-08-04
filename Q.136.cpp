#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        // // Brute Force Approach
        // int count = 0;
        // for(int i=0;i<nums.size();i++)
        // {
        //     int num = nums[i];
        //     for(int j=0;j<nums.size();j++)
        //     {
        //         if(nums[j]==nums[i])
        //             count++;
        //     }
        //     if(count==1)
        //         return nums[i];
        // }
        // return -1;

        // // Better Approach
        // unordered_map<int, int> hash;
        // for (int num : nums) {
        //     hash[num]++;
        // }
        // for (auto& it : hash) {
        //     if (it.second == 1) {
        //         return it.first;
        //     }
        // }
        // return -1;        

        // Optimised Code
        int xor1 = 0;
        for(auto it : nums) {
            xor1 ^= it;
        }        
        return xor1;
    }
};

int main() {
    Solution sol;

    // Example 1: [4, 1, 2, 1, 2]
    vector<int> nums1 = {4, 1, 2, 1, 2};
    int single1 = sol.singleNumber(nums1);
    cout << "Single number in [4, 1, 2, 1, 2]: " << single1 << endl;

    // Example 2: [2, 2, 1]
    vector<int> nums2 = {2, 2, 1};
    int single2 = sol.singleNumber(nums2);
    cout << "Single number in [2, 2, 1]: " << single2 << endl;

    // Example 3: [1]
    vector<int> nums3 = {1};
    int single3 = sol.singleNumber(nums3);
    cout << "Single number in [1]: " << single3 << endl;
    
    return 0;
}
