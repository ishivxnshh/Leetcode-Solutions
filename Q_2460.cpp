#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(nums[i] == nums[i+1])
            {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        vector<int> vec(nums.size(), 0);
        int j = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != 0)
            {
                vec[j++] = nums[i];
            }
        }
        return vec;
    }
};

// Driver code to test the function
int main() {
    Solution sol;
    vector<int> nums = {2, 2, 0, 4, 4, 8};
    
    vector<int> result = sol.applyOperations(nums);
    
    cout << "Output: ";
    for(int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
