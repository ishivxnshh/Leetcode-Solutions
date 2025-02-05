#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        // My Approach
        // if(nums.size()==1)
        //     return nums[0];
        // int low = 0, high = nums.size()-1;
        // while(low<=high)
        // {
        //     int mid = (low+high)/2;
        //     if(mid!=0 && mid!=nums.size() && (nums[mid]!=nums[mid-1]) && (nums[mid]!=nums[mid+1]))
        //         return nums[mid];             
        //     else if((nums[mid]==nums[mid-1]) && mid%2==0)
        //         high = mid-2;
        //     else if((nums[mid]==nums[mid+1]) && (nums.size()-mid)%2==0)
        //         high = mid-1;
        //     else
        //         low = mid+1;
        // }
        // return -1;

        //enhanced approach
        int n = nums.size();
        if(n==1)
            return nums[0];
        if(nums[0]!=nums[1])
            return nums[0];
        if(nums[n-1]!=nums[n-2])
            return nums[n-1];
        int low = 1, high = n-2;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if((nums[mid]!=nums[mid-1]) && (nums[mid]!=nums[mid+1]))
                return nums[mid];        
            else if((nums[mid]==nums[mid-1] && mid%2==0) || (nums[mid]==nums[mid+1] && (nums.size()-mid)%2==0))
                high = mid-1;
            else
                low = mid+1;
        }
        return -1;
    }
};

// Driver Code
int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> nums1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << "Single Non-Duplicate (Test 1): " << solution.singleNonDuplicate(nums1) << endl;

    // Test Case 2
    vector<int> nums2 = {3, 3, 7, 7, 10, 11, 11};
    cout << "Single Non-Duplicate (Test 2): " << solution.singleNonDuplicate(nums2) << endl;

    // Test Case 3
    vector<int> nums3 = {1, 1, 2};
    cout << "Single Non-Duplicate (Test 3): " << solution.singleNonDuplicate(nums3) << endl;

    return 0;
}