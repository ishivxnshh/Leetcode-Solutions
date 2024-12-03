#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int startIndex = 1;
        while (true) {
            bool isValid = true;
            int sum = startIndex;
            for (int i = 0; i < nums.size(); i++) {
                sum += nums[i];
                if (sum < 1) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                return startIndex;
            }
            startIndex++;
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-3, 2, -3, 4, 2}; // Example input
    int result = sol.minStartValue(nums);
    cout << "Minimum start value: " << result << endl;

    return 0;
}