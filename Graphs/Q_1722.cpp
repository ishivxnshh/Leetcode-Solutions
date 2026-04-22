#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> fa;
    vector<int> rank;

    // Find with path compression
    int find(int x)
    {
        if (fa[x] != x)
        {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }

    // Union by rank
    void Union(int x, int y)
    {
        x = find(x);
        y = find(y);

        if (x == y) return;

        if (rank[x] < rank[y])
        {
            swap(x, y);
        }

        fa[y] = x;

        if (rank[x] == rank[y])
        {
            rank[x]++;
        }
    }

public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target,
                               vector<vector<int>>& allowedSwaps)
    {
        int n = source.size();

        fa.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
        {
            fa[i] = i;
        }

        // Build DSU
        for (auto& p : allowedSwaps)
        {
            Union(p[0], p[1]);
        }

        // Group elements
        unordered_map<int, unordered_map<int, int>> sets;

        for (int i = 0; i < n; i++)
        {
            int parent = find(i);
            sets[parent][source[i]]++;
        }

        // Compare with target
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int parent = find(i);

            if (sets[parent][target[i]] > 0)
            {
                sets[parent][target[i]]--;
            }
            else
            {
                ans++;
            }
        }

        return ans;
    }
};


int main()
{
    Solution obj;

    // Test Case 1
    vector<int> source1 = {1, 2, 3, 4};
    vector<int> target1 = {2, 1, 4, 5};
    vector<vector<int>> swaps1 =
    {
        {0, 1},
        {2, 3}
    };

    cout << "Output 1: " 
         << obj.minimumHammingDistance(source1, target1, swaps1) << endl;
    // Expected: 1

    // Test Case 2
    vector<int> source2 = {1, 2, 3, 4};
    vector<int> target2 = {1, 3, 2, 4};
    vector<vector<int>> swaps2 =
    {
        {1, 2}
    };

    cout << "Output 2: " 
         << obj.minimumHammingDistance(source2, target2, swaps2) << endl;
    // Expected: 0

    // Test Case 3 (no swaps)
    vector<int> source3 = {5, 1, 2};
    vector<int> target3 = {1, 5, 2};
    vector<vector<int>> swaps3 = {};

    cout << "Output 3: " 
         << obj.minimumHammingDistance(source3, target3, swaps3) << endl;
    // Expected: 2

    return 0;
}