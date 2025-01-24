#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        // vector<int> res(2 * n);
        // int a = 0, b = n, i = 0;
        // while (a < n) {
        //     res[i++] = nums[a++];
        //     res[i++] = nums[b++];
        // }
        // return res;

        // or

        vector<int> res;
        for (int i = 0; i < n; ++i) {
            res.push_back(nums[i]);
            res.push_back(nums[i + n]);
        }
        return res;
    }
};

void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {2, 5, 1, 3, 4, 7};
    int n1 = 3;
    vector<int> result1 = solution.shuffle(nums1, n1);
    cout << "Test Case 1: ";
    printVector(result1);

    // Test case 2
    vector<int> nums2 = {1, 2, 3, 4, 4, 3, 2, 1};
    int n2 = 4;
    vector<int> result2 = solution.shuffle(nums2, n2);
    cout << "Test Case 2: ";
    printVector(result2);

    // Test case 3
    vector<int> nums3 = {1, 1, 2, 2};
    int n3 = 2;
    vector<int> result3 = solution.shuffle(nums3, n3);
    cout << "Test Case 3: ";
    printVector(result3);

    return 0;
}
