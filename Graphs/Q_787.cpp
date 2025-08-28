#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        // Time Complexity: O(n + E), where E is the number of flights (edges).
        // Space Complexity: O(n + E), for the adjacency list and distance array.
        
        // Create adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // Queue for BFS: {stops, {node, cost}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        // Distance array
        vector<int> distance(n, 1e9);
        distance[src] = 0;

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if (stops > k) 
                continue;

            for (auto p : adj[node])
            {
                int adjNode = p.first;
                int edjW = p.second;

                if (cost + edjW < distance[adjNode])
                {
                    distance[adjNode] = cost + edjW;
                    q.push({stops + 1, {adjNode, distance[adjNode]}});
                }
            }
        }
        return (distance[dst] == 1e9) ? -1 : distance[dst];
    }
};

// ---------- DRIVER CODE ----------
int main() 
{
    int n, m;
    cout << "Enter number of nodes (n) and number of flights (m): ";
    cin >> n >> m;

    vector<vector<int>> flights(m, vector<int>(3));
    cout << "Enter flights (u v w):\n";
    for (int i = 0; i < m; i++) 
    {
        cin >> flights[i][0] >> flights[i][1] >> flights[i][2];
    }

    int src, dst, k;
    cout << "Enter source, destination, and max stops (k): ";
    cin >> src >> dst >> k;

    Solution obj;
    int result = obj.findCheapestPrice(n, flights, src, dst, k);
    cout << "Cheapest Price: " << result << endl;

    return 0;
}
