#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int maxi = 0;
        for(int i = 1; i < points.size(); i++) {
            maxi = max(maxi, (points[i][0] - points[i-1][0]));
        }
        return maxi;
    }
};

// Driver Code
int main() {
    Solution solution;

    // Test Case 1
    vector<vector<int>> points1 = {{8, 7}, {9, 9}, {7, 4}, {2, 3}};
    cout << "Max Width of Vertical Area (Test Case 1): " 
         << solution.maxWidthOfVerticalArea(points1) << endl;

    // Test Case 2
    vector<vector<int>> points2 = {{3, 1}, {9, 5}, {1, 6}, {7, 2}};
    cout << "Max Width of Vertical Area (Test Case 2): " 
         << solution.maxWidthOfVerticalArea(points2) << endl;

    return 0;
}