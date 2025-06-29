#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int M = 1e9 + 7;
        int n = nums.size();

        // Precompute powers of 2 modulo M
        vector<int> pow(n);
        pow[0] = 1;
        for (int i = 1; i < n; i++) {
            pow[i] = (pow[i - 1] * 2LL) % M;  // Use 2LL to avoid overflow
        }

        sort(nums.begin(), nums.end());
        int l = 0, r = n - 1;
        int res = 0;

        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                res = (res + pow[r - l]) % M;
                l++;
            } else {
                r--;
            }
        }

        return res;
    }
};

// Driver code
int main() {
    Solution sol;

    vector<int> nums = {3, 5, 6, 7};
    int target = 9;

    int result = sol.numSubseq(nums, target);
    cout << "Number of valid subsequences: " << result << endl;

    return 0;
}