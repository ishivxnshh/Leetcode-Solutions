#include <bits/stdc++.h>

using namespace std;

class Solution 
{
public:
    int romanToInt(string s) 
    {
        unordered_map<char, int> mpp = 
        {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},  
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int count = 0;

        for (int i = 0; i < s.size(); i++) 
        {
            if (i < s.size() - 1 && mpp[s[i]] < mpp[s[i + 1]]) 
            {
                count -= mpp[s[i]];  // Subtract smaller value if next value is greater
            }
            else 
            {
                count += mpp[s[i]];  // Otherwise, add normally
            }
        }

        return count;
    }
};

// Driver Code
int main() 
{
    Solution obj;

    vector<string> testCases = {"III", "IV", "IX", "LVIII", "MCMXCIV"};

    for (string test : testCases) 
    {
        cout << "Roman: " << test << " => Integer: " << obj.romanToInt(test) << endl;
    }

    return 0;
}