#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool judgeCircle(string moves)
    {
        int x = 0;
        int y = 0;

        for (auto &ch : moves)
        {
            if (ch == 'R') x++;
            else if (ch == 'L') x--;
            else if (ch == 'U') y++;
            else y--;
        }

        return (x == 0 && y == 0);
    }
};

int main()
{
    Solution obj;

    vector<string> testCases =
    {
        "UD",        // true
        "LL",        // false
        "URDL",      // true
        "UUDDLRLR",  // true
        "UUUD",      // false
        "",          // true (no movement)
    };

    for (int i = 0; i < testCases.size(); i++)
    {
        string moves = testCases[i];

        bool result = obj.judgeCircle(moves);

        cout << "Test Case " << i + 1 << ":\n";
        cout << "Moves: \"" << moves << "\"\n";
        cout << "Returns to origin: " << (result ? "true" : "false") << "\n";
        cout << "--------------------------\n";
    }

    return 0;
}