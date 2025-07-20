#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// TC: O(V + E)
// SC: O(V)

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathVis, vector<int>& check) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : graph[node]) {
            if (!vis[it]) {
                if (dfs(it, graph, vis, pathVis, check))
                    return true;
            }
            else if (pathVis[it] == 1)
                return true;
        }

        pathVis[node] = 0;
        check[node] = 1; // Mark as safe
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // DFS + Cycle Detection
        // int V = graph.size();
        // vector<int> vis(V, 0), pathVis(V, 0), check(V, 0);
        // vector<int> safeNodes;

        // for (int i = 0; i < V; i++) {
        //     if (!vis[i])
        //         dfs(i, graph, vis, pathVis, check);
        // }

        // for (int i = 0; i < V; i++) {
        //     if (check[i] == 1)
        //         safeNodes.push_back(i);
        // }
        // return safeNodes;

        // Kahn's Algorithm / BFS
        int V = graph.size();
        vector<vector<int>> adjRev(V, vector<int>());
        vector<int> inDegree(V, 0); 
        for (int i = 0; i < V; i++)
        {
            for (auto& it : graph[i])
            {
                adjRev[it].push_back(i);
                inDegree[i]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }
        vector<int> safeNodes;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for (auto& it : adjRev[node])
            {
                inDegree[it]--;
                if (inDegree[it] == 0) q.push(it);
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};

// ---------- Driver Code ----------
int main() {
    Solution obj;

    // Sample graph
    vector<vector<int>> graph = {
        {1, 2},   // Node 0
        {2, 3},   // Node 1
        {5},      // Node 2
        {0},      // Node 3
        {5},      // Node 4
        {},       // Node 5
        {}        // Node 6
    };

    vector<int> result = obj.eventualSafeNodes(graph);

    cout << "Eventual Safe Nodes: ";
    for (int node : result)
        cout << node << " ";
    cout << endl;

    return 0;
}