#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        // Brute-Force Approach (tc: O(n1+n2), sc: O(n1+n2))
        // vector<int> merged;
        // int i = 0;
        // int j = 0;
        // while(i < nums1.size() && j < nums2.size())
        // {
        //     if(nums1[i] < nums2[j])
        //         merged.push_back(nums1[i++]);
        //     else
        //         merged.push_back(nums2[j++]);
        // }
        // while(i < nums1.size())
        // {
        //     merged.push_back(nums1[i++]);
        // }
        // while(j < nums2.size())
        // {
        //     merged.push_back(nums2[j++]);
        // }
        // int total = merged.size();
        // if (total % 2 == 1) 
        // {
        //     return static_cast<double>(merged[total / 2]);
        // } 
        // else 
        // {
        //     int middle1 = merged[total / 2 - 1];
        //     int middle2 = merged[total / 2];
        //     return (static_cast<double>(middle1) + static_cast<double>(middle2)) / 2;
        // }

        // Optimal Approach (tc: O(n1+n2)/2, sc: O(n1+n2)), Worst Case TC: O(n1+n2)
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0;
        int j = 0;
        int n = n1 + n2;
        int ind2 = n / 2;
        int ind1 = ind2 - 1;
        int ind1el = 0;
        int ind2el = 0;
        int count = 0;

        while (i < n1 && j < n2 && count <= ind2)
        {
            if (nums1[i] < nums2[j])
            {
                if (count == ind1) ind1el = nums1[i];
                if (count == ind2) ind2el = nums1[i];
                i++;
            }
            else
            {
                if (count == ind1) ind1el = nums2[j];
                if (count == ind2) ind2el = nums2[j];
                j++;
            }
            count++;
        }

        while (i < n1 && count <= ind2)
        {
            if (count == ind1) ind1el = nums1[i];
            if (count == ind2) ind2el = nums1[i];
            i++;
            count++;
        }

        while (j < n2 && count <= ind2)
        {
            if (count == ind1) ind1el = nums2[j];
            if (count == ind2) ind2el = nums2[j];
            j++;
            count++;
        }

        if (n % 2 == 0)
            return (double)(ind1el + ind2el) / 2.0;
        else
            return (double)ind2el;
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