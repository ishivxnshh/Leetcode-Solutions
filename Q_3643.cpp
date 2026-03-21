#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) 
    {
        for (int i = y; i < y + k; i++)
        {
            int top = x;
            int bottom = x + k - 1;

            while (top < bottom)
            {
                swap(grid[top++][i], grid[bottom--][i]);
            }
        }
        return grid;
    }
};

int main()
{
    Solution obj;

    // Sample input
    vector<vector<int>> grid =
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12},
        {13,14,15,16}
    };

    int x = 1; // starting row
    int y = 1; // starting column
    int k = 2; // size of submatrix

    vector<vector<int>> result = obj.reverseSubmatrix(grid, x, y, k);

    // Print result
    for (auto &row : result)
    {
        for (auto &val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
