#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int maxi = *max_element(candies.begin(), candies.end());
        int n = candies.size();
        vector<bool> res(n, false);

        for (int i = 0; i < n; i++)
        {
            if (candies[i] + extraCandies >= maxi)
            {
                res[i] = true;
            }
        }

        return res;
    }
};

// Driver code
int main()
{
    Solution sol;
    vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;

    vector<bool> result = sol.kidsWithCandies(candies, extraCandies);

    cout << "Result: ";
    for (bool val : result)
    {
        cout << (val ? "true" : "false") << " ";
    }
    cout << endl;

    return 0;
}