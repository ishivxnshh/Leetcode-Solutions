#include <bits/stdc++.h>
using namespace std;

struct DisjointSet {
    vector<int> rank, parent;

    DisjointSet(int n)
    {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;   
    }

    int findPar(int u)
    {
        if (parent[u] == u) return u;
        return parent[u] = findPar(parent[u]); // path compression
    }

    void UnionByRank(int u, int v)
    {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if (ulp_u == ulp_v) return;

        if (rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;
        else if (rank[ulp_v] < rank[ulp_u])
            parent[ulp_v] = ulp_u;
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0, maxCol = 0;
        for (auto& it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DisjointSet ds(maxRow + maxCol + 2);
        unordered_map<int, int> stoneNodes;

        for (auto& it : stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.UnionByRank(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        int count = 0;
        for (auto& it : stoneNodes)
            if (ds.findPar(it.first) == it.first)
                count++;

        return stones.size() - count;
    }
};

// ---------------- Driver Code ----------------
int main() {
    int n;
    cout << "Enter number of stones: ";
    cin >> n;

    vector<vector<int>> stones(n, vector<int>(2));
    cout << "Enter stone coordinates (row col):" << endl;
    for (int i = 0; i < n; i++)
        cin >> stones[i][0] >> stones[i][1];

    Solution obj;
    cout << "Maximum stones that can be removed: " << obj.removeStones(stones) << endl;

    return 0;
}