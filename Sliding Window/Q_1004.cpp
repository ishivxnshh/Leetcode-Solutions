#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int zeroes = 0;
        int l = 0;
        int r = 0;
        int n = nums.size();
        int maxi = 0;

        while (r < n)
        {
            if (nums[r] == 0)
            {
                zeroes++;
            }

            while (zeroes > k)
            {
                if (nums[l] == 0)
                    zeroes--;
                l++;
            }

            maxi = max(maxi, r - l + 1);
            r++;
        }

        return maxi;
    }
};

int main() {
    int n, k;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements (0 or 1): ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << "Enter k: ";
    cin >> k;

    Solution obj;
    cout << "Longest consecutive ones = " << obj.longestOnes(nums, k) << endl;

    return 0;
}