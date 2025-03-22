#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int, int> mpp;
        for(auto& num : nums)
        {
            mpp[num]++;
        }
        for(auto& [k,v] : mpp)
        {
            if(v % 2 != 0)
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {3, 3, 2, 2, 2, 2};
    cout << (sol.divideArray(nums1) ? "true" : "false") << endl; // Expected output: true
    
    vector<int> nums2 = {1, 2, 3, 4};
    cout << (sol.divideArray(nums2) ? "true" : "false") << endl; // Expected output: false

    vector<int> nums3 = {6, 6, 6, 6, 6, 6};
    cout << (sol.divideArray(nums3) ? "true" : "false") << endl; // Expected output: true
    
    return 0;
}