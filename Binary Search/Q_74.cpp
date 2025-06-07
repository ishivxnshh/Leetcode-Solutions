#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool binarySearch(vector<int> vec, int target)
    {
        int low = 0;
        int high = vec.size() - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (vec[mid] == target)
                return true;
            else if (vec[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // Brute-Force Approach (tc: O(m + logn), sc: O(1))
        // int m = matrix.size();
        // int n = matrix[0].size();
        // for (int i = 0; i < m; i++)
        // {
        //     if (matrix[i][0] <= target && target <= matrix[i][n - 1])
        //     {
        //         if (binarySearch(matrix[i], target))
        //             return true;
        //     }
        // }
        // return false;

        // Better Approach (tc: O(logm + logn), sc: O(1))
        // int up = 0;
        // int down = matrix.size() - 1;
        // int row = 0;
        // while (up <= down)
        // {
        //     int mid = (up + down) / 2;
        //     if (matrix[mid][0] == target)
        //     {
        //         return true;
        //     }
        //     else if (matrix[mid][0] < target)
        //     {
        //         up = mid + 1;
        //     }
        //     else
        //     {
        //         down = mid - 1;
        //     }
        // }
        // if (down < 0)
        // {
        //     return false;
        // }
        // row = down;
        // return binarySearch(matrix[row], target);

        // Optimal Approach (tc: O(log(m * n)), sc:O(1))
        int low = 0;
        int high = matrix.size() * matrix[0].size() - 1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            int row = mid / matrix[0].size();
            int col = mid % matrix[0].size();
            if(matrix[row][col] == target)
                return true;
            else if(matrix[row][col] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> matrix1 = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    int target1 = 3;

    vector<vector<int>> matrix2 = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    int target2 = 13;

    cout << "Test Case 1: " << (sol.searchMatrix(matrix1, target1) ? "Found" : "Not Found") << endl;
    cout << "Test Case 2: " << (sol.searchMatrix(matrix2, target2) ? "Found" : "Not Found") << endl;

    return 0;
}