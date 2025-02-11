#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution
{
public:
    vector<int> queryResults(int limit, vector<vector<int>> &queries)
    {
        // Brute Force Approach (tc: n^2, sc:n) (tle) (tcs passeed: 547/551)
        // map<int, int> mpp;
        // vector<int> vec;

        // for (int i = 0; i < queries.size(); i++)
        // {
        //     set<int> st;
        //     mpp[queries[i][0]] = queries[i][1];

        //     for (auto it : mpp)
        //     {
        //         st.insert(it.second);
        //     }

        //     vec.push_back(st.size());
        // }

        // return vec;

        // Optimized Approach (tc: n, sc: n)
        vector<int> vec;
        unordered_map<int, int> mpp1;
        unordered_map<int, int> mpp2;
        for(int i=0; i<queries.size(); i++)
        {
            if(mpp1.find(queries[i][0])!=mpp1.end())
            {
                int a = mpp1[queries[i][0]];
                mpp2[a]--;
                if(mpp2[a]==0)
                    mpp2.erase(a);
            }
            mpp1[queries[i][0]] = queries[i][1];
            mpp2[queries[i][1]]++;
            vec.push_back(mpp2.size());
        }
        return vec;
    }
};

// **Driver Code**
int main()
{
    Solution sol;

    // **Test Case 1**
    int limit1 = 5;
    vector<vector<int>> queries1 = {{1, 2}, {2, 3}, {3, 2}, {4, 3}, {1, 5}};
    vector<int> result1 = sol.queryResults(limit1, queries1);

    cout << "Test Case 1 Output: ";
    for (int num : result1)
    {
        cout << num << " ";
    }
    cout << endl;

    // **Test Case 2**
    int limit2 = 10;
    vector<vector<int>> queries2 = {{3, 7}, {2, 5}, {3, 5}, {1, 7}, {4, 8}, {2, 9}};
    vector<int> result2 = sol.queryResults(limit2, queries2);

    cout << "Test Case 2 Output: ";
    for (int num : result2)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}