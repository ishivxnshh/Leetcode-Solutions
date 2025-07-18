#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(int node, int color, vector<vector<int>>& graph, vector<int>& vis_color) {
        vis_color[node] = color;
        color = !color;
        for (auto it : graph[node]) {
            if (vis_color[it] == -1) {
                if (!dfs(it, color, graph, vis_color)) return false;
            }
            else if (vis_color[it] == vis_color[node]) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis_color(V, -1); // -1 = unvisited
        for (int i = 0; i < V; i++) {
            if (vis_color[i] == -1) {
                if (!dfs(i, 0, graph, vis_color)) return false;
            }
        }
        return true;
    }
};

// -------------------------
//        DRIVER CODE
// -------------------------
int main() {
    Solution obj;

    // Test Case 1: Bipartite Graph
    vector<vector<int>> graph1 = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };
    cout << "Graph 1 is Bipartite? " << (obj.isBipartite(graph1) ? "Yes" : "No") << endl;

    // Test Case 2: Not Bipartite
    vector<vector<int>> graph2 = {
        {1, 2, 3},
        {0, 2},
        {0, 1, 3},
        {0, 2}
    };
    cout << "Graph 2 is Bipartite? " << (obj.isBipartite(graph2) ? "Yes" : "No") << endl;

    // Test Case 3: Disconnected Bipartite
    vector<vector<int>> graph3 = {
        {},         // 0
        {2},        // 1
        {1},        // 2
        {},         // 3
        {5},        // 4
        {4}         // 5
    };
    cout << "Graph 3 is Bipartite? " << (obj.isBipartite(graph3) ? "Yes" : "No") << endl;

    return 0;
}