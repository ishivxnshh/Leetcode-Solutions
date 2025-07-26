#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maXarea = 0;
        while(left < right) {
            maXarea = (int) max(1LL * maXarea, 1LL * (right - left) * min(height[left], height[right]));
            if(height[left] <= height[right])
                left++;
            else 
                right--;
        }
        return maXarea;
    }
};

// Driver Code
int main() {
    Solution sol;

    // Test Case 1
    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Max Area (Test Case 1): " << sol.maxArea(height1) << endl;  // Expected: 49

    // Test Case 2
    vector<int> height2 = {1, 1};
    cout << "Max Area (Test Case 2): " << sol.maxArea(height2) << endl;  // Expected: 1

    // Test Case 3
    vector<int> height3 = {4, 3, 2, 1, 4};
    cout << "Max Area (Test Case 3): " << sol.maxArea(height3) << endl;  // Expected: 16

    // Test Case 4
    vector<int> height4 = {1, 2, 1};
    cout << "Max Area (Test Case 4): " << sol.maxArea(height4) << endl;  // Expected: 2

    return 0;
}