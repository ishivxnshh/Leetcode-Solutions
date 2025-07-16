#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int countEven = 0;
        int countOdd = 0;

        for (int &num : nums)
        {
            if (num % 2 == 0)
                countEven++;
            else
                countOdd++;
        }

        int parity = nums[0] % 2;
        int alternating = 1;

        for (int i = 1; i < n; i++)
        {
            int currParity = nums[i] % 2;
            if (currParity != parity)
            {
                alternating++;
                parity = currParity;
            }
        }

        return max({countEven, countOdd, alternating});
    }
};

// ------------------ DRIVER CODE ------------------
int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 4, 5};
    cout << "Output 1: " << sol.maximumLength(nums1) << endl; // Expected: 5 (alternating)

    vector<int> nums2 = {2, 4, 6, 8};
    cout << "Output 2: " << sol.maximumLength(nums2) << endl; // Expected: 4 (all even)

    vector<int> nums3 = {1, 3, 5, 7};
    cout << "Output 3: " << sol.maximumLength(nums3) << endl; // Expected: 4 (all odd)

    vector<int> nums4 = {1, 1, 2, 2, 1, 1, 2};
    cout << "Output 4: " << sol.maximumLength(nums4) << endl; // Expected: 4 (even count = 3, odd count = 4, alternating = 5)

    return 0;
}