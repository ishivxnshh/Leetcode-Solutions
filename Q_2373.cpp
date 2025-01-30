#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMax(vector<vector<int>>& grid, int row, int col) {
        int maxi = 0;
        for (int i = row; i <= row + 2; i++) {
            for (int j = col; j <= col + 2; j++) {
                maxi = max(maxi, grid[i][j]);
            }
        }
        return maxi;
    }

    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> maxLocal(n - 2, vector<int>(n - 2, 0));
        for (int row = 0; row < n - 2; row++) {
            for (int col = 0; col < n - 2; col++) {
                maxLocal[row][col] = findMax(grid, row, col);
            }
        }
        return maxLocal;
    }
};

// Driver Code
int main() {
    Solution solution;

    // Test Case 1: General case
    vector<vector<int>> grid1 = {
        {9, 9, 8, 1},
        {5, 6, 2, 6},
        {8, 2, 6, 4},
        {6, 2, 2, 2}
    };
    
    vector<vector<int>> result1 = solution.largestLocal(grid1);
    
    cout << "Max local grid:\n";
    for (const auto& row : result1) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    // Test Case 2: Larger Grid
    vector<vector<int>> grid2 = {
        {1, 2, 3, 4, 5},
        {5, 6, 7, 8, 9},
        {9, 10, 11, 12, 13},
        {13, 14, 15, 16, 17},
        {17, 18, 19, 20, 21}
    };

    vector<vector<int>> result2 = solution.largestLocal(grid2);
    
    cout << "\nMax local grid:\n";
    for (const auto& row : result2) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
