#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // Brute-Force Approach (TC: O(n³), sc(WORST CASE):O(n³))
        // vector<vector<int>> vec;
        // set<vector<int>> st;
        // for(int i = 0; i < nums.size(); i++) {
        //     for(int j = i + 1; j < nums.size(); j++) {
        //         for(int k = j + 1; k < nums.size(); k++) {
        //             if(nums[i] + nums[j] + nums[k] == 0) {
        //                 vector<int> temp = {nums[i], nums[j], nums[k]};
        //                 sort(temp.begin(), temp.end());
        //                 st.insert(temp);
        //             }
        //         }
        //     }
        // }
        // for(auto it: st) {
        //     vec.push_back(it);
        // }
        // return vec;

        //Better Approach ()
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    
    vector<vector<int>> result = sol.threeSum(nums);
    
    // Output the result
    for(auto triplet : result) {
        for(int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
