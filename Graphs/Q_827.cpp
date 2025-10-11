#include <bits/stdc++.h>
using namespace std;

struct DisjointSet {
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    } 

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        
        // step 1: build connected components
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                for (int i = 0; i < 4; i++) {
                    int newR = r + dr[i];
                    int newC = c + dc[i];
                    if (newR >= 0 && newR < n && newC >= 0 && newC < n && grid[newR][newC] == 1) {
                        ds.unionBySize(r * n + c, newR * n + newC);
                    }
                }
            }
        }

        // step 2: try converting each 0 to 1
        int mx = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                set<int> components;
                for (int i = 0; i < 4; i++) {
                    int newR = r + dr[i];
                    int newC = c + dc[i];
                    if (newR >= 0 && newR < n && newC >= 0 && newC < n && grid[newR][newC] == 1) {
                        components.insert(ds.findUPar(newR * n + newC));
                    }
                }
                int sizeT = 1;
                for (auto it : components) {
                    sizeT += ds.size[it];
                }
                mx = max(mx, sizeT);
            }
        }
        return (mx == 0) ? n * n : mx;
    }
};

// ------------------ Driver Code ------------------
int main() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    cout << obj.largestIsland(grid) << endl;
    return 0;
}