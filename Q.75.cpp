#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Dutch National Flag algorithm
        int start = 0, mid = 0, end = nums.size() - 1;
        while (mid <= end) {
            if (nums[mid] == 0) {
                swap(nums[start], nums[mid]);
                start++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[end], nums[mid]);
                end--;
            }
        }
    }
};

// Driver code
int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {2, 0, 2, 1, 1, 0}; // Input array

    cout << "Original array 1: ";
    for (int num : nums1)
        cout << num << " ";
    cout << endl;
    
    sol.sortColors(nums1);  // Sorting the array

    cout << "Sorted array 1: ";
    for (int num : nums1)
        cout << num << " ";
    cout << endl;

    // Test Case 2
    vector<int> nums2 = {2, 0, 1};  // Additional test case

    cout << "\nOriginal array 2: ";
    for (int num : nums2)
        cout << num << " ";
    cout << endl;

    sol.sortColors(nums2);  // Sorting the array

    cout << "Sorted array 2: ";
    for (int num : nums2)
        cout << num << " ";
    cout << endl;

    return 0;
}
