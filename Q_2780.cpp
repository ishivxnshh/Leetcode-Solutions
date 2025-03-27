#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int, int> mpp;
        int dom = nums[0];
        int f = 1;
        for (auto num : nums) {
            mpp[num]++;
            if (mpp[num] > f) {
                dom = num;
                f = mpp[num];
            }
        }
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == dom)
                f--;
            if (((mpp[dom] - f) * 2) > (i + 1) && (f * 2) > (nums.size() - i - 1))
                return i;
        }
        return -1;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 2, 2, 2};  // Sample test case
    int result = obj.minimumIndex(nums);

    cout << "Minimum index: " << result << endl;

    return 0;
}