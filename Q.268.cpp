#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        // // Approach-1
        // sort(nums.begin(), nums.end());
        // int i=0;
        // while(i<nums.size())
        // {
        //     if(nums[i]!=i)
        //     {
        //         return i;
        //         break;
        //     }
        //     i++;
        // }
        // return i;

        // // Approach-2
        // const int n = nums.size();
        // int* hash = new int[n + 1];
        // fill(hash, hash+(n+1), 0);
        // for (int i = 0; i < n; i++)
        //     hash[nums[i]]++;
        // for (int i = 0; i <= n; i++) {
        //     if (hash[i] == 0)
        //     {
        //         delete[] hash;
        //         return i;
        //     }
        // }
        // delete[] hash;
        // return -1;

        // // Approach-3
        // int n = nums.size();
        // int total_sum = n * (n + 1) / 2; // Sum of first n natural numbers
        // int array_sum = 0;
        // for (int i = 0; i < n; i++) {
        //     array_sum += nums[i];
        // }
        // return total_sum - array_sum;

        // // Approach-4(most optimal)
        int xor1 = 0,xor2 = 0;
        for(int i=0;i<nums.size();i++)
        {
            xor1 = xor1^(i);
            xor2 = xor2^nums[i];
        }
        xor1 = xor1^nums.size();
        return xor1^xor2;
        
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {3, 0, 1};
    cout << "Missing number in [3, 0, 1]: " << solution.missingNumber(nums1) << endl;

    // Test case 2
    vector<int> nums2 = {0, 1};
    cout << "Missing number in [0, 1]: " << solution.missingNumber(nums2) << endl;

    // Test case 3
    vector<int> nums3 = {9,6,4,2,3,5,7,0,1};
    cout << "Missing number in [9, 6, 4, 2, 3, 5, 7, 0, 1]: " << solution.missingNumber(nums3) << endl;

    return 0;
}