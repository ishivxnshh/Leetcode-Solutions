#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPaths(int n, vector<vector<int>>& roads)
    {
        // adjacency list: node -> {neighbor, weight}
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        // priority queue of {distance, node}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n, 1e18); // use large INF
        vector<int> ways(n, 0);
        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;
        int mod = (int)(1e9 + 7);
        while (!pq.empty())
        {
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto it : adj[node])
            {
                int adjNode = it.first;
                long long edW = it.second;
                // found shorter distance
                if (dis + edW < dist[adjNode])
                {
                    dist[adjNode] = dis + edW;
                    pq.push({dis + edW, adjNode});
                    ways[adjNode] = ways[node];
                }
                // found another shortest path
                else if (dis + edW == dist[adjNode])
                {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};

// Driver Code
int main()
{
    Solution sol;

    // Test Case 1
    int n1 = 7;
    vector<vector<int>> roads1 = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3},
                                  {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1},
                                  {0, 4, 5}, {4, 6, 2}};
    cout << sol.countPaths(n1, roads1) << endl;
    // Expected Output: 4

    // Test Case 2
    int n2 = 2;
    vector<vector<int>> roads2 = {{0, 1, 1}};
    cout << sol.countPaths(n2, roads2) << endl;
    // Expected Output: 1

    return 0;
}