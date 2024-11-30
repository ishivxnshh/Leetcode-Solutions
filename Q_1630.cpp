#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;
        for (int i = 0; i < l.size(); i++) {
            int start = l[i], end = r[i];
            vector<int> sub(nums.begin() + start, nums.begin() + end + 1);
            
            sort(sub.begin(), sub.end());
            int diff = sub[1] - sub[0];
            bool isArithmetic = true;

            for (int j = 1; j < sub.size(); j++) {
                if (sub[j] - sub[j - 1] != diff) {
                    isArithmetic = false;
                    break;
                }
            }
            res.push_back(isArithmetic);
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {4, 6, 5, 9, 3, 7};
    vector<int> l1 = {0, 0, 2};
    vector<int> r1 = {2, 3, 5};
    vector<bool> res1 = sol.checkArithmeticSubarrays(nums1, l1, r1);

    cout << "Test Case 1:" << endl;
    for (bool val : res1) {
        cout << (val ? "true" : "false") << " ";
    }
    cout << endl;

    // Test Case 2
    vector<int> nums2 = {-12, -9, -3, -12, -6, 15, 20, -25, -20, -15, -10};
    vector<int> l2 = {0, 1, 6, 4, 8, 7};
    vector<int> r2 = {4, 4, 9, 7, 9, 10};
    vector<bool> res2 = sol.checkArithmeticSubarrays(nums2, l2, r2);

    cout << "Test Case 2:" << endl;
    for (bool val : res2) {
        cout << (val ? "true" : "false") << " ";
    }
    cout << endl;

    return 0;
}
