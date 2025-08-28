#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time Complexity: O(N * M * log(N * M))
    // Space Complexity: O(N * M)
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        // using similar approach as Dijkstra's algorithm
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> difference(n, vector<int>(m, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq; // {diff, {row, col}}

        difference[0][0] = 0;
        pq.push({0, {0, 0}});

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;

            // If destination is reached, return the effort
            if (r == n - 1 && c == m - 1)
                return diff;

            for (int i = 0; i < 4; i++)
            {
                int newR = r + delRow[i];
                int newC = c + delCol[i];

                // Check boundaries
                if (newR >= 0 && newR < n && newC >= 0 && newC < m)
                {
                    int newEffort = max(abs(heights[r][c] - heights[newR][newC]), diff);

                    if (newEffort < difference[newR][newC])
                    {
                        difference[newR][newC] = newEffort;
                        pq.push({newEffort, {newR, newC}});
                    }
                }
            }
        }

        return 0; // Fallback (should never reach here)
    }
};

// ---------- Driver Code ----------
int main()
{
    Solution obj;

    vector<vector<int>> heights1 = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    cout << "Test Case 1: " << obj.minimumEffortPath(heights1) << endl; // Expected: 2

    vector<vector<int>> heights2 = {{1, 2, 3}, {3, 8, 4}, {5, 3, 5}};
    cout << "Test Case 2: " << obj.minimumEffortPath(heights2) << endl; // Expected: 1

    vector<vector<int>> heights3 = {{1, 2, 1, 1, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 1, 1, 2, 1}};
    cout << "Test Case 3: " << obj.minimumEffortPath(heights3) << endl; // Expected: 0

    return 0;
}