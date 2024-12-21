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

        //Better Approach (TC: O(n^2*logm), sc(WORST CASE):O(n+2*no. of unique triplets))
        // vector<vector<int>> vec;
        // set<vector<int>> st;
        // for(int i=0;i<nums.size();i++)
        // {
        //     set<int> st1;
        //     for(int j=i+1;j<nums.size();j++)
        //     {
        //         int third = -(nums[i] + nums[j]);
        //         if(st1.find(third)!=st1.end())
        //         {
        //             vector<int> temp = {nums[i], nums[j], third};
        //             sort(temp.begin(), temp.end());
        //             st.insert(temp);
        //         }
        //         st1.insert(nums[j]);
        //     }
        // }
        // for(auto it:st)
        // {
        //     vec.push_back(it);
        // }
        // return vec;

        // Optimized Approach (TC: O(nlogn + n^2), sc(WORST CASE):O(no. of unique triplets))
        vector<vector<int>> vec;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int j = i + 1;
            int k = nums.size() - 1;
            while(j<k)
            {
                int sum = nums[i]+nums[j]+nums[k];
                if(sum<0)
                {
                    j++;
                }
                else if(sum>0)
                {
                    k--;
                }
                else
                {
                    vec.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1])
                        j++;
                    while(j<k && nums[k]==nums[k+1])
                        k--;
                }
            }
        }
        return vec;
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
