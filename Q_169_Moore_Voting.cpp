#include <iostream>
#include <vector>
#include <algorithm>  // For sort function
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        // Brute Force Approach(TC: nlogn, SC: logn)
        // sort(nums.begin(), nums.end());
        // int n = nums.size();
        // return nums[n/2];  // Majority element is at index n/2 after sorting

        // Better Approach(TC: )
        int n = nums.size();
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++){
            m[nums[i]]++;
        }
        for(auto x: m){
            if(x.second > n/2){
                return x.first;
            }
        }
        return 0;
    }
};

// Driver code to test the solution
int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {3, 2, 3};
    cout << "Test Case 1: ";
    cout << "Majority Element = " << solution.majorityElement(nums1) << endl;

    // Test case 2
    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    cout << "Test Case 2: ";
    cout << "Majority Element = " << solution.majorityElement(nums2) << endl;

    return 0;
}
