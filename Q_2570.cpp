#include <bits/stdc++.h>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) 
    {
        map<int, int> mpp;

        for (int i = 0; i < nums1.size(); i++)
        {
            mpp[nums1[i][0]] += nums1[i][1];
        }

        for (int i = 0; i < nums2.size(); i++)
        {
            mpp[nums2[i][0]] += nums2[i][1];
        }

        vector<vector<int>> vec;

        for (auto it : mpp)
        {
            vec.push_back({it.first, it.second});
        }

        return vec;
    }
};

// Driver Code
int main() 
{
    Solution obj;

    vector<vector<int>> nums1 = {{1, 3}, {2, 2}, {4, 5}};
    vector<vector<int>> nums2 = {{1, 2}, {3, 4}, {4, 1}};

    vector<vector<int>> result = obj.mergeArrays(nums1, nums2);

    cout << "Merged Arrays:" << endl;
    
    for (auto row : result) 
    {
        cout << "[" << row[0] << ", " << row[1] << "]" << endl;
    }

    return 0;
}
