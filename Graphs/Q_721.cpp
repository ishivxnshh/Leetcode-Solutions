#include <bits/stdc++.h>
using namespace std;

// ---------------- Disjoint Set ----------------
struct DisjointSet
{
    vector<int> rank, parent;

    DisjointSet(int n)
    {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findPar(int u)
    {
        if (parent[u] == u)
        {
            return u;
        }
        return parent[u] = findPar(parent[u]);
    }

    void UnionByRank(int u, int v)
    {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

        if (ulp_u == ulp_v)
        {
            return;
        }

        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

// ---------------- Solution Class ----------------
class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mapMailnode;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string mail = accounts[i][j];
                if (mapMailnode.find(mail) == mapMailnode.end())
                {
                    mapMailnode[mail] = i;
                }
                else
                {
                    ds.UnionByRank(i, mapMailnode[mail]);
                }
            }
        }
        
        vector<vector<string>> mergedMail(n);
        for (auto it : mapMailnode)
        {
            string mail = it.first;
            int node = ds.findPar(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++)
        {
            if (mergedMail[i].empty())
            {
                continue;
            }

            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for (auto &mail : mergedMail[i])
            {
                temp.push_back(mail);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};

// ---------------- Driver Code ----------------
int main()
{
    int n;
    cout << "Enter number of accounts: ";
    cin >> n;

    vector<vector<string>> accounts(n);

    cout << "Enter account details (first name, then emails):\n";
    for (int i = 0; i < n; i++)
    {
        int m;
        cout << "Number of entries for account " << i + 1 << " (name + emails): ";
        cin >> m;
        accounts[i].resize(m);

        for (int j = 0; j < m; j++)
        {
            cin >> accounts[i][j];
        }
    }

    Solution obj;
    vector<vector<string>> ans = obj.accountsMerge(accounts);

    cout << "\nMerged Accounts:\n";
    for (auto &acc : ans)
    {
        for (auto &str : acc)
        {
            cout << str << " ";
        }
        cout << "\n";
    }

    return 0;
}

/*
-----------------------------------
🧮 Time Complexity (TC):
O(N × α(N) + M log M)
where N = number of accounts, M = total number of unique emails.

💾 Space Complexity (SC):
O(N + M)
for DSU arrays, email map, and merged result.
-----------------------------------
*/