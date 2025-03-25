#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0, sign = 1;
        long res = 0;

        // trimming leading spaces
        while (i < s.size() && s[i] == ' ')
        {
            i++;
        }
        if (i == s.size())
        {
            return 0;
        }

        // check for sign
        if (s[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if (s[i] == '+')
        {
            i++;
        }

        // process numbers
        while (i < s.size() && isdigit(s[i]))
        {
            res = res * 10 + (s[i] - '0');

            // handle overflow
            if (sign * res > INT_MAX)
            {
                return INT_MAX;
            }
            if (sign * res < INT_MIN)
            {
                return INT_MIN;
            }
            i++;
        }
        return (int)(sign * res);
    }
};

// Driver code
int main()
{
    Solution solution;

    vector<string> testCases = 
    {
        "42",
        "   -42",
        "4193 with words",
        "words and 987",
        "-91283472332",
        "2147483648",
        "    +123",
        "00000-42a1234"
    };

    for (const string &test : testCases)
    {
        cout << "Input: \"" << test << "\" -> Output: " << solution.myAtoi(test) << endl;
    }

    return 0;
}