#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Function to find maximum distance between consecutive set bits
    // TC: O(1)  (loop runs fixed 32 times)
    // SC: O(1)
    int binaryGap(int n) 
    {
        int prev = -1;
        int res = 0;

        for (int curr = 0; curr < 32; curr++)
        {
            if (((n >> curr) & 1) > 0)
            {
                if (prev != -1)
                {
                    res = max(res, curr - prev);
                }
                prev = curr;
            }
        }

        return res;
    }
};


// ---------------- DRIVER CODE ----------------
// TC: O(T)
// SC: O(1)

int main()
{
    Solution obj;

    // Predefined Test Cases
    vector<int> testCases = 
    {
        22,   // 10110 -> answer = 2
        8,    // 1000  -> answer = 0
        5,    // 101   -> answer = 2
        6,    // 110   -> answer = 1
        1     // 1     -> answer = 0
    };

    for (int i = 0; i < testCases.size(); i++)
    {
        cout << "Test Case " << i + 1 
             << " (" << testCases[i] << ") -> ";

        cout << obj.binaryGap(testCases[i]) << endl;
    }

    return 0;
}
