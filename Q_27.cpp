#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            if (nums[l] == val) {
                nums[l] = nums[r];
                r--;
            } else {
                l++;
            }
        }
        return l;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {3, 2, 2, 3}; // Example 1
    int val1 = 3;
    int newLength1 = sol.removeElement(nums1, val1);

    cout << "New length (Example 1): " << newLength1 << endl;
    cout << "Modified array (Example 1): ";
    for (int i = 0; i < newLength1; i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;

    vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2}; // Example 2
    int val2 = 2;
    int newLength2 = sol.removeElement(nums2, val2);

    cout << "New length (Example 2): " << newLength2 << endl;
    cout << "Modified array (Example 2): ";
    for (int i = 0; i < newLength2; i++) {
        cout << nums2[i] << " ";
    }
    cout << endl;

    return 0;
}
