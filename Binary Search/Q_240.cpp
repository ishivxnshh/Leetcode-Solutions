#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = 0;
        int column = matrix[0].size() - 1;

        while (row <= (int)matrix.size() - 1 && column >= 0)
        {
            if (matrix[row][column] == target)
            {
                return true;
            }
            else if (target > matrix[row][column])
            {
                row++;
            }
            else
            {
                column--;
            }
        }

        return false;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> matrix1 = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target1 = 5;

    vector<vector<int>> matrix2 = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target2 = 20;

    cout << "Test Case 1: " << (sol.searchMatrix(matrix1, target1) ? "Found" : "Not Found") << endl;
    cout << "Test Case 2: " << (sol.searchMatrix(matrix2, target2) ? "Found" : "Not Found") << endl;

    return 0;
}