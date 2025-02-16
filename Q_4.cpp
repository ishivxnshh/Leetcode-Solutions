#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        // Brute-Force Approach (tc: (n+m)log(n+m), sc:n+m)
        int n = nums1.size();
        int m = nums2.size();
        vector<int> merged;
        
        for (int i = 0; i < n; i++) 
        {
            merged.push_back(nums1[i]);
        }
        for (int i = 0; i < m; i++) 
        {
            merged.push_back(nums2[i]);
        }
        
        sort(merged.begin(), merged.end());
        int total = merged.size();
        
        if (total % 2 == 1) 
        {
            return static_cast<double>(merged[total / 2]);
        } 
        else 
        {
            int middle1 = merged[total / 2 - 1];
            int middle2 = merged[total / 2];
            return (static_cast<double>(middle1) + static_cast<double>(middle2)) / 2;
        }

        // Better Approach 
    }
};

// Driver Code
int main() 
{
    Solution solution;
    
    // Sample Test Cases
    vector<int> nums1_1 = {1, 3};
    vector<int> nums2_1 = {2};
    cout << "Median: " << solution.findMedianSortedArrays(nums1_1, nums2_1) << endl;
    
    vector<int> nums1_2 = {1, 2};
    vector<int> nums2_2 = {3, 4};
    cout << "Median: " << solution.findMedianSortedArrays(nums1_2, nums2_2) << endl;
    
    vector<int> nums1_3 = {0, 0};
    vector<int> nums2_3 = {0, 0};
    cout << "Median: " << solution.findMedianSortedArrays(nums1_3, nums2_3) << endl;
    
    vector<int> nums1_4 = {};
    vector<int> nums2_4 = {1};
    cout << "Median: " << solution.findMedianSortedArrays(nums1_4, nums2_4) << endl;
    
    vector<int> nums1_5 = {2};
    vector<int> nums2_5 = {};
    cout << "Median: " << solution.findMedianSortedArrays(nums1_5, nums2_5) << endl;
    
    return 0;
}