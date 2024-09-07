#include <iostream>
#include <vector>
#include <algorithm> // For std::next_permutation

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};

// Function to print the array
void printArray(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    Solution solution;

    // Test Case 1
    vector<int> nums1 = {1, 2, 3};
    solution.nextPermutation(nums1);
    cout << "Test Case 1 - Next permutation: ";
    printArray(nums1);

    // Test Case 2
    vector<int> nums2 = {3, 2, 1};
    solution.nextPermutation(nums2);
    cout << "Test Case 2 - Next permutation: ";
    printArray(nums2);

    // Test Case 3
    vector<int> nums3 = {1, 1, 5};
    solution.nextPermutation(nums3);
    cout << "Test Case 3 - Next permutation: ";
    printArray(nums3);

    return 0;
}
