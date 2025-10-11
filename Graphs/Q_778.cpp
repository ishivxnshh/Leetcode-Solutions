#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N² * log(N²)) ≈ O(N² log N)
// Space Complexity: O(N²)

class Solution
{
public:
    int delR[4] = {-1, 0, 1, 0};
    int delC[4] = {0, 1, 0, -1};

    bool possibleToReach(vector<vector<int>> &grid, int i, int j, int t, vector<vector<bool>> &vis)
    {
        int n = grid.size();
        if (i < 0 || i >= n || j < 0 || j >= n || vis[i][j] || grid[i][j] > t)
            return false;

        vis[i][j] = true;
        if (i == n - 1 && j == n - 1)
            return true;

        for (int k = 0; k < 4; k++)
        {
            int ni = i + delR[k];
            int nj = j + delC[k];
            if (possibleToReach(grid, ni, nj, t, vis))
                return true;
        }
        return false;
    }

    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int l = grid[0][0];
        int r = n * n - 1;
        int result = 0;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            vector<vector<bool>> vis(n, vector<bool>(n, false));

            if (possibleToReach(grid, 0, 0, mid, vis))
            {
                result = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return result;
    }
};

// ---------- Driver Code ----------
int main()
{
    Solution obj;

    int n;
    cout << "Enter grid size (n): ";
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    cout << "Enter grid elements:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    int ans = obj.swimInWater(grid);
    cout << "Minimum time to reach destination: " << ans << endl;

    return 0;
}