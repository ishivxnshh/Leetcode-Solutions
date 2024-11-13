#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

    // Brute-Force Approach(TC: N^2, SC:1)
    //     int count = 0;
    //     for (int i = 0; i < nums.size(); i++) {
    //         int prod = 1;
    //         for (int j = i; j < nums.size(); j++) {
    //             prod *= nums[j];
    //             if (prod >= k) 
    //                 break;
    //             count++;
    //         }
    //     }
    //     return count;
        
        
    }
};

// Driver code
int main() {
    Solution solution;
    
    // Example input
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    
    int result = solution.numSubarrayProductLessThanK(nums, k);
    cout << "Number of subarrays with product less than " << k << ": " << result << endl;
    
    return 0;
}
