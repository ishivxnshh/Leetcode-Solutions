#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(V^2)
// Space Complexity: O(V) for visited array + O(V) recursion stack

class Solution
{
public:
    void dfs(int node, vector<int> &visited, vector<vector<int>> &isConnected, int V)
    {
        visited[node] = 1;
        for (int j = 0; j < V; j++)
        {
            if (isConnected[node][j] == 1 && !visited[j])
            {
                dfs(j, visited, isConnected, V);
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {

        // can also be done converting from adjacency matrix to adjacency list
        int V = isConnected.size();
        vector<int> visited(V, 0);
        int count = 0;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, isConnected, V);
                count++;
            }
        }
        return count;
    }
};

// -------------------- DRIVER CODE --------------------

int main()
{
    Solution sol;

    // Sample input 1
    vector<vector<int>> isConnected1 = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}};
    cout << "Output 1: " << sol.findCircleNum(isConnected1) << endl; // Expected: 2

    // Sample input 2
    vector<vector<int>> isConnected2 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}};
    cout << "Output 2: " << sol.findCircleNum(isConnected2) << endl; // Expected: 3

    return 0;
}
