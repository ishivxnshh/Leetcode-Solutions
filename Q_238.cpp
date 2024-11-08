#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        //Brute Force Approach (TC: n^2, SC: n) (TLE)
        // vector<int> answer;
        // for(int i = 0; i < nums.size(); i++)
        // {
        //     int mul = 1;
        //     for(int j = 0; j < nums.size(); j++)
        //     {
        //         if(i==j)
        //         {
        //             continue;
        //         }
        //         else
        //         {
        //             mul*=nums[j];
        //         }
        //     }
        //     answer.push_back(mul);
        // }
        // return answer;
                
        
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> result1 = solution.productExceptSelf(nums1);
    
    cout << "Product of array except self for [1, 2, 3, 4]: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 2
    vector<int> nums2 = {-1, 1, 0, -3, 3};
    vector<int> result2 = solution.productExceptSelf(nums2);
    
    cout << "Product of array except self for [-1, 1, 0, -3, 3]: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
