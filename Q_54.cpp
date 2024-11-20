#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> vec;
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0, bottom = m - 1, left = 0, right = n - 1;

        while (top <= bottom && left <= right) {

            for (int i = left; i <= right; i++)
            {
                vec.push_back(matrix[top][i]);
            }
            top++;

            for (int i = top; i <= bottom; i++)
            {
                vec.push_back(matrix[i][right]);
            }
            right--;

            if(top<=bottom)
            {
                for(int i = right; i >= left; i--)
                {
                    vec.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if(left<=right)
            {
                for(int i = bottom; i >= top; i--)
                {
                    vec.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return vec;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<int> result1 = sol.spiralOrder(matrix1);
    cout << "Test Case 1 Spiral Order: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    // Test Case 2
    vector<vector<int>> matrix2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    vector<int> result2 = sol.spiralOrder(matrix2);
    cout << "Test Case 2 Spiral Order: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
