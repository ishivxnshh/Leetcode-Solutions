#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        //Brute-Force Approach (TC: n*n, SC: n*n)
        // int n = matrix.size();
        // vector<vector<int>> rotated(n, vector<int>(n, 0));
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         rotated[j][n - i - 1] = matrix[i][j];
        //     }
        // }
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         matrix[i][j] = rotated[i][j];
        //     }
        // }

        //Optimal Approach (TC: O(N*N) + O(N*N) = O(N*N), SC: 1)
        int n = matrix.size();
        for(int i = 0; i < n-1; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for (int i = 0; i < n; i++) 
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main() {
    Solution sol;

    // Define a sample matrix
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Display original matrix
    cout << "Original Matrix:" << endl;
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    // Rotate the matrix
    sol.rotate(matrix);

    // Display rotated matrix
    cout << "\nRotated Matrix:" << endl;
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}
