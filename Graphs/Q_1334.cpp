#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> dist(n, vector<int>(n, 1e8));

        // Fill initial edge weights
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        // Self-loops
        for (int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }

        // Floyd–Warshall
        for (int via = 0; via < n; via++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][via] == 100000000 || dist[via][j] == 100000000)
                        continue;
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }

        // Find city with minimum reachable count (break ties by larger index)
        int ans = -1;
        int count = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            int c = 0;
            for (int j = 0; j < n; j++)
            {
                if (dist[i][j] <= distanceThreshold)
                    c++;
            }

            if (c <= count)
            {
                count = c;
                ans = i;
            }
        }

        return ans;
    }
};

// Driver code
int main()
{
    Solution obj;

    int n = 4;
    vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
    int distanceThreshold = 4;

    cout << obj.findTheCity(n, edges, distanceThreshold) << endl;

    return 0;
}