#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
    }
};

int main() {
    Solution solution;

    // Predefined test case
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    cout << "Before merge:\nNums1: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << "\nNums2: ";
    for (int num : nums2) {
        cout << num << " ";
    }
    cout << "\n";

    // Call the merge function
    solution.merge(nums1, m, nums2, n);

    // Output the merged array
    cout << "After merge:\nNums1: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}