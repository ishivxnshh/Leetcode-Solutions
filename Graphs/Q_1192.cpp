#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int timer = 0;

    void dfs(int node, int parent, vector<int> adj[], vector<int>& vis, 
             int tin[], int low[], vector<vector<int>>& bridges)
    {
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        
        for (auto it : adj[node])
        {
            if (it == parent) continue;
            if (!vis[it])
            {
                dfs(it, node, adj, vis, tin, low, bridges);
                low[node] = min(low[node], low[it]);
                // Bridge found
                if (low[it] > tin[node]) 
                    bridges.push_back({node, it});
            }
            else
            {
                low[node] = min(low[node], tin[it]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        vector<int> adj[n];
        for (auto& it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);
        int tin[n], low[n];
        vector<vector<int>> bridges;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
                dfs(i, -1, adj, vis, tin, low, bridges);
        }

        return bridges;
    }
};

// 🧩 Driver Code
int main() {
    Solution obj;

    // Sample Test Case 1
    int n1 = 4;
    vector<vector<int>> connections1 = {{0,1}, {1,2}, {2,0}, {1,3}};
    vector<vector<int>> ans1 = obj.criticalConnections(n1, connections1);
    cout << "Critical Connections (Test 1):\n";
    for (auto &v : ans1)
        cout << "[" << v[0] << ", " << v[1] << "] ";
    cout << "\n\n";

    // Sample Test Case 2
    int n2 = 5;
    vector<vector<int>> connections2 = {{0,1}, {1,2}, {2,3}, {3,4}, {2,4}};
    vector<vector<int>> ans2 = obj.criticalConnections(n2, connections2);
    cout << "Critical Connections (Test 2):\n";
    for (auto &v : ans2)
        cout << "[" << v[0] << ", " << v[1] << "] ";
    cout << "\n";

    return 0;
}