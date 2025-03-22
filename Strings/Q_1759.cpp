#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int MOD = static_cast<int>(1e9 + 7);

    long long factype(long long n) 
    {
        return ((n * (n + 1)) / 2) % MOD;
    }

    int countHomogenous(string s) 
    {
        vector<int> vec;
        int count = 1;

        for (int i = 1; i < s.length(); i++) 
        {
            if (s[i] != s[i - 1]) 
            {
                vec.push_back(count);
                count = 1;
            } 
            else 
            {
                count++;
            }
        }
        vec.push_back(count);

        long long res = 0;
        for (auto& num : vec) 
        {
            res = (res + factype(num)) % MOD;
        }

        return static_cast<int>(res);
    }
};

// **Driver Code**
int main() 
{
    Solution sol;

    vector<string> testCases = {
        "abbcccaa",   // Expected Output: 13
        "zzzzz",      // Expected Output: 15
        "abc",        // Expected Output: 3
        "a",          // Expected Output: 1
        "aaaa",       // Expected Output: 10
        "ababab",     // Expected Output: 6
        "bbbbbbbbb"   // Expected Output: 45
    };

    for (const string& test : testCases) 
    {
        cout << "Input: " << test << " -> Output: " << sol.countHomogenous(test) << endl;
    }

    return 0;
}