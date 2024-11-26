#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int xxxor = 0;
        for(auto it: nums) {
            mpp[it]++;
        }
        int flag = 0;
        for(auto it: mpp) {
            if(it.second == 2) {  // Check if the element appears twice
                xxxor ^= it.first;  // Perform XOR with the duplicate element
                flag = 1;
            }
        }
        if(flag == 1) {
            return xxxor;  // Return the result if a duplicate is found
        } else {
            return 0;  // Return 0 if no duplicate is found
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};  // Example input

    int result = solution.duplicateNumbersXOR(nums);
    if(result != 0) {
        cout << "Duplicate number found: " << result << endl;
    } else {
        cout << "No duplicate number." << endl;
    }

    return 0;
}
