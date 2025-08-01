#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inOrder(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for (auto edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
            inOrder[edge[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inOrder[i] == 0)
                q.push(i);
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto it : adj[node]) {
                inOrder[it]--;
                if (inOrder[it] == 0)
                    q.push(it);
            }
        }

        return (topo.size() == numCourses ? topo : vector<int>());
    }
};

// ----------------------------------------
// ✅ Driver Code
// ----------------------------------------
int main() {
    Solution sol;

    // Example 1: No cycle
    int numCourses1 = 4;
    vector<vector<int>> prerequisites1 = {{1, 0}, {2, 1}, {3, 2}};
    vector<int> order1 = sol.findOrder(numCourses1, prerequisites1);

    cout << "Course Order (Example 1): ";
    if (!order1.empty()) {
        for (int course : order1)
            cout << course << " ";
    } else {
        cout << "Cycle detected. No valid order.";
    }
    cout << endl;

    // Example 2: With cycle
    int numCourses2 = 3;
    vector<vector<int>> prerequisites2 = {{0, 1}, {1, 2}, {2, 0}};
    vector<int> order2 = sol.findOrder(numCourses2, prerequisites2);

    cout << "Course Order (Example 2): ";
    if (!order2.empty()) {
        for (int course : order2)
            cout << course << " ";
    } else {
        cout << "Cycle detected. No valid order.";
    }
    cout << endl;

    return 0;
}