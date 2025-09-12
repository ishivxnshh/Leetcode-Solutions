#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        // Build adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for (auto &time : times)
        {
            adj[time[0] - 1].push_back({time[1] - 1, time[2]});
        }

        // Distance array
        vector<int> dist(n, INT_MAX);
        dist[k - 1] = 0;

        // Min-heap {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k - 1});

        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u])
                continue;

            for (auto &[v, w] : adj[u])
            {
                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        int ans = *max_element(dist.begin(), dist.end());
        return ans == INT_MAX ? -1 : ans;
    }
};

// ---------------- DRIVER CODE ----------------
int main()
{
    Solution sol;

    // Sample Test Case
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n = 4, k = 2;

    cout << sol.networkDelayTime(times, n, k) << endl; // Expected Output: 2

    return 0;
}

/*
Time Complexity (TC):
    Building adjacency: O(E)
    Dijkstra (with priority queue): O((V + E) log V)
    Overall: O((V + E) log V)

Space Complexity (SC):
    Adjacency list: O(V + E)
    Distance array: O(V)
    Priority queue: O(V)
    Overall: O(V + E)
*/