#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        // TC: O(N)
        // SC: O(1)

        int res = INT_MAX;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                if (abs(i - start) < res) 
                {
                    res = abs(i - start);             
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {1, 2, 3, 4, 5};
    int target1 = 5;
    int start1 = 3;

    cout << "Output 1: " << obj.getMinDistance(nums1, target1, start1) << endl;
    // Expected: 1

    // Test Case 2
    vector<int> nums2 = {5, 3, 6};
    int target2 = 5;
    int start2 = 2;

    cout << "Output 2: " << obj.getMinDistance(nums2, target2, start2) << endl;
    // Expected: 2

    // Test Case 3
    vector<int> nums3 = {2, 4, 6, 8, 6};
    int target3 = 6;
    int start3 = 3;

    cout << "Output 3: " << obj.getMinDistance(nums3, target3, start3) << endl;
    // Expected: 1

    return 0;
}