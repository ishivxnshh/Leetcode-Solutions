#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int left = 0;
        int right = nums.size()-1;
        while(left<=right)
        {
            int mid = left + (right - left)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            if(nums[left]<nums[mid])
            {
                if(target<nums[left] && target<nums[mid])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else
            {
                if(target<=nums[right] && target>nums[mid])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    
    int result = solution.search(nums, target);
    
    if (result != -1) {
        cout << "Target found at index: " << result << endl;
    } else {
        cout << "Target not found" << endl;
    }
    
    return 0;
}
