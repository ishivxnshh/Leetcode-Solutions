#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    void solve(string &num, int target, int index, string path, long value, long prev, vector<string> &ans)
    {
        if (index == num.length())
        {
            if (value == target)
            {
                ans.push_back(path);
            }
            return;
        }

        long curr = 0;
        string currStr = "";

        for (int i = index; i < num.length(); i++)
        {
            if (i > index && num[index] == '0') break;

            currStr += num[i];
            curr = curr * 10 + (num[i] - '0');

            if (index == 0)
            {
                solve(num, target, i + 1, currStr, curr, curr, ans);
            }
            else
            {
                // +
                solve(num, target, i + 1, path + "+" + currStr, value + curr, curr, ans);

                // -
                solve(num, target, i + 1, path + "-" + currStr, value - curr, -curr, ans);

                // *
                solve(num, target, i + 1, path + "*" + currStr,
                      value - prev + (prev * curr),
                      prev * curr,
                      ans);
            }
        }
    }

    vector<string> addOperators(string num, int target) 
    {
        vector<string> ans;
        solve(num, target, 0, "", 0, 0, ans);
        return ans;
    }
};

int main()
{
    Solution obj;

    string num = "123";
    int target = 6;

    vector<string> result = obj.addOperators(num, target);

    cout << "Expressions:\n";
    for (auto &exp : result)
    {
        cout << exp << endl;
    }

    return 0;
}
