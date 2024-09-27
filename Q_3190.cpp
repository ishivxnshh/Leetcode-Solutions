#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        //Made by Me
        // int count = 0;
        // for(int i = 0; i < nums.size(); i++)
        // {
        //     int flag = nums[i]%3;
        //     if(flag==1)
        //     {
        //         nums[i]-=1;
        //         flag-=1;
        //         count+=1;
        //     }
        //     if(flag==2)
        //     {
        //         nums[i]+=1;
        //         flag+=1;
        //         count+=1;
        //     }
        // }    

        //simplified        
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] % 3 != 0)
                count++;
        }
        return count;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {1, 2, 3, 4};
    int result1 = sol.minimumOperations(nums1);
    cout << "Test Case 1 - The minimum number of operations: " << result1 << endl;

    // Test case 2
    vector<int> nums2 = {3, 6, 9};
    int result2 = sol.minimumOperations(nums2);
    cout << "Test Case 2 - The minimum number of operations: " << result2 << endl;

    return 0;
}
