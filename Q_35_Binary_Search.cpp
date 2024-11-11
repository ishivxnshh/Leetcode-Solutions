#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = end + (start - end) / 2;
            if (target == nums[mid]) {
                return mid;
            } else if (target < nums[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    // Call the function and print the result
    int result = solution.searchInsert(nums, target);
    cout << "The index for target " << target << " is: " << result << endl;

    // You can test with other values of target as well
    target = 2;
    result = solution.searchInsert(nums, target);
    cout << "The index for target " << target << " is: " << result << endl;

    target = 7;
    result = solution.searchInsert(nums, target);
    cout << "The index for target " << target << " is: " << result << endl;

    target = 0;
    result = solution.searchInsert(nums, target);
    cout << "The index for target " << target << " is: " << result << endl;

    return 0;
}
