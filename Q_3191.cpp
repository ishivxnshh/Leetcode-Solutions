#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int minOperations(vector<int>& nums) 
    {  
        int count = 0;
        
        for (int i = 0; i <= nums.size() - 3; i++) 
        {
            if (nums[i] == 0) 
            {
                nums[i] = 1;
                nums[i + 1] = (nums[i + 1] == 0) ? 1 : 0;
                nums[i + 2] = (nums[i + 2] == 0) ? 1 : 0;
                count++;
            }
        }

        if (nums[nums.size() - 2] == 1 && nums[nums.size() - 1] == 1)
        {
            return count;
        }
        else
        {
            return -1;
        }
    }
};

// Driver Code
int main() 
{
    Solution solution;

    // Test Case 1
    vector<int> nums1 = {0, 1, 0, 1, 0};
    cout << "Test Case 1: " << solution.minOperations(nums1) << endl;

    // Test Case 2
    vector<int> nums2 = {1, 1, 1, 0, 0};
    cout << "Test Case 2: " << solution.minOperations(nums2) << endl;

    // Test Case 3
    vector<int> nums3 = {0, 0, 0, 0, 0};
    cout << "Test Case 3: " << solution.minOperations(nums3) << endl;

    return 0;
}