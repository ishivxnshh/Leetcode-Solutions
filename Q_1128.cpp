#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    // Time Complexity: O(n), where n is the number of dominoes
    // Space Complexity: O(n), for storing counts in the map
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        unordered_map<int, int> mpp;
        int sum = 0;

        for (int i = 0; i < dominoes.size(); i++)
        {
            int a = dominoes[i][0];
            int b = dominoes[i][1];
            int key = a <= b ? a * 10 + b : b * 10 + a; // Normalize to a unique key
            mpp[key]++;
        }

        for (auto it : mpp)
        {
            if (it.second > 1)
            {
                sum += (it.second * (it.second - 1)) / 2; // nC2 pairs
            }
        }

        return sum;
    }
};

// ---------- Driver Code ----------
int main()
{
    Solution obj;

    // Sample Test Case
    vector<vector<int>> dominoes = {
        {1, 2}, {2, 1}, {3, 4}, {5, 6}, {4, 3}, {2, 1}
    };

    int result = obj.numEquivDominoPairs(dominoes);
    cout << "Number of equivalent domino pairs: " << result << endl;

    return 0;
}