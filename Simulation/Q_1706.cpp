#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int solve(int col, vector<vector<int>>& grid, int n, int m)
    {
        int r = 0;
        int c = col;

        while (r < n)
        {
            if (grid[r][c] == 1)
            {
                if (c == m - 1 || grid[r][c + 1] == -1)
                    return -1;

                r++;
                c++;
            }
            else
            {
                if (c == 0 || grid[r][c - 1] == 1)
                    return -1;

                r++;
                c--;
            }
        }
        return c;
    }

    vector<int> findBall(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> res(m);

        for (int col = 0; col < m; col++)
        {
            res[col] = solve(col, grid, n, m);
        }

        return res;
    }
};

int main() 
{
    Solution obj;

    vector<vector<int>> grid = 
    {
        {1, 1, 1, -1, -1},
        {1, 1, 1, -1, -1},
        {-1, -1, -1, 1, 1},
        {1, 1, 1, 1, -1},
        {-1, -1, -1, -1, -1}
    };

    vector<int> result = obj.findBall(grid);

    cout << "Output: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}