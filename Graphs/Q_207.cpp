#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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

        return topo.size() == numCourses;
    }
};

// -----------------------------------
// ✅ Driver Code
// -----------------------------------
int main() {
    Solution sol;

    // Example 1: No cycle
    int numCourses1 = 4;
    vector<vector<int>> prerequisites1 = {{1, 0}, {2, 1}, {3, 2}};
    cout << "Can finish courses (Example 1)? " << sol.canFinish(numCourses1, prerequisites1) << endl;

    // Example 2: Cycle exists
    int numCourses2 = 3;
    vector<vector<int>> prerequisites2 = {{0, 1}, {1, 2}, {2, 0}};
    cout << "Can finish courses (Example 2)? " << sol.canFinish(numCourses2, prerequisites2) << endl;

    return 0;
}