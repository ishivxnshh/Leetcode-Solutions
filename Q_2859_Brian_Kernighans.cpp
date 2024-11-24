#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {

        // Brute-Force Approach (TC: nLogn, sc: 1)
        // long sum = 0;
        // for (int i = 0; i < nums.size(); i++) 
        // {
        //     if(i==0 && k==0)
        //     {
        //         sum += nums[0];
        //     }
        //     else
        //     {
        //         int count = 0;
        //         int temp = i;
        //         while(temp > 0)
        //         {
        //             if(temp % 2 != 0)
        //                 count++;
        //             temp /= 2;
        //         }
        //         if(count == k)
        //         {
        //             sum += nums[i];
        //         }
        //     }
        // }
        // return sum;

        // Brian Kernighan’s Algoithm
        //optimized soln (TC: nLogn, sc: 1)
        int sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            int count = 0;
            int temp = i;
            while(temp>0)
            {
                temp = temp&(temp-1); 
                count++;
            } 
            if(count==k)
                sum+=nums[i];
        }
        return sum;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {5, 10, 1, 5, 2};
    int k1 = 1;
    int result1 = sol.sumIndicesWithKSetBits(nums1, k1);
    cout << "Test Case 1: " << result1 << endl; // Expected output: 15

    // Test case 2
    vector<int> nums2 = {4, 3, 2, 1};
    int k2 = 2;
    int result2 = sol.sumIndicesWithKSetBits(nums2, k2);
    cout << "Test Case 2: " << result2 << endl; // Expected output: 1

    return 0;
}
