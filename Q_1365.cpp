#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(auto it:nums) 
            mpp[it]++;
        for(int i=0;i<nums.size();i++)
        {
            int count = 0;
            for(auto it:mpp)
            {
                if(it.first<nums[i])
                    count+=it.second;
            }
            nums[i] = count;
        }
        return nums;
    }
};

// **Driver Code**
int main() {
    Solution sol;
    vector<int> nums = {8, 1, 2, 2, 3};
    
    vector<int> result = sol.smallerNumbersThanCurrent(nums);
    
    cout << "Output: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
