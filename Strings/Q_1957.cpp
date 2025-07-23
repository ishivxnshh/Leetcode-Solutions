#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string makeFancyString(string s)
    {
        string res = "";
        res += s[0];
        int count = 1;
        int i = 1;
        while (i < s.size())
        {
            if (res.back() == s[i])
            {
                if (count == 2)
                {
                    i++;
                    continue;
                }
                else
                {
                    res += s[i];
                    count++;
                }
            }
            else
            {
                res += s[i];
                count = 1;
            }
            i++;
        }
        return res;
    }
};

int main()
{
    Solution sol;

    // Sample input
    string input = "aaabaaaa";

    // Call function
    string output = sol.makeFancyString(input);

    // Output result
    cout << "Processed string: " << output << endl;

    return 0;
}