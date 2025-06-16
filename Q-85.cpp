#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the largest rectangle area in a histogram
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int maxi = 0;

        for (int i = 0; i < heights.size(); i++) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                int ele = heights[stk.top()];
                stk.pop();
                int nse = i;
                int pse = (stk.empty() ? -1 : stk.top());
                maxi = max(maxi, ele * (nse - pse - 1));
            }
            stk.push(i);
        }

        // Handle remaining bars in the stack
        while (!stk.empty()) {
            int ele = heights[stk.top()];
            stk.pop();
            int nse = heights.size();
            int pse = (stk.empty() ? -1 : stk.top());
            maxi = max(maxi, ele * (nse - pse - 1));
        }

        return maxi;
    }

    // Function to find the maximal rectangle of 1s in a binary matrix
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> preSum(m, vector<int>(n, 0));

        // Build histogram heights row-wise
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < m; j++) {
                sum += 1;
                if (matrix[j][i] == '0') sum = 0;
                preSum[j][i] = sum;
            }
        }
        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            maxArea = max(maxArea, largestRectangleArea(preSum[i]));
        }
        return maxArea;
    }
};

// Driver code
int main() {
    Solution obj;

    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    cout << obj.maximalRectangle(matrix) << endl; // Expected Output: 6

    return 0;
}