#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions)
    {
        int n = positions.size();
        vector<int> actual_index(n);
        iota(actual_index.begin(), actual_index.end(), 0);

        auto lambda = [&](int i, int j)
        {
            return positions[i] < positions[j];
        };

        sort(actual_index.begin(), actual_index.end(), lambda);

        vector<int> res;
        stack<int> stk;

        for (auto &curr_index : actual_index)
        {
            if (directions[curr_index] == 'R')
            {
                stk.push(curr_index);
            }
            else
            {
                while (!stk.empty() && healths[curr_index] > 0)
                {
                    int top_index = stk.top();
                    stk.pop();

                    if (healths[top_index] > healths[curr_index])
                    {
                        healths[top_index] -= 1;
                        healths[curr_index] = 0;
                        stk.push(top_index);
                    }
                    else if (healths[top_index] < healths[curr_index])
                    {
                        healths[top_index] = 0;
                        healths[curr_index] -= 1;
                    }
                    else
                    {
                        healths[top_index] = 0;
                        healths[curr_index] = 0;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (healths[i])
            {
                res.push_back(healths[i]);
            }
        }

        return res;
    }
};

int main()
{
    Solution obj;

    vector<int> positions = {5, 4, 3, 2, 1};
    vector<int> healths = {2, 17, 9, 15, 10};
    string directions = "RRRRR";

    vector<int> result = obj.survivedRobotsHealths(positions, healths, directions);

    cout << "Survived Robots Healths: ";
    for (auto val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}