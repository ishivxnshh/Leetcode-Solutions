#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mirrorDistance(int n) 
    {
        // TC: O(d)  -> d = number of digits
        // SC: O(1)

        int m = n;
        int rev = 0;

        while (m)
        {
            rev = rev * 10 + m % 10;
            m /= 10;
        }

        return abs(rev - n);
    }
};

int main()
{
    Solution obj;

    // 🔹 Test Cases
    vector<int> testCases = {123, 100, 0, 7, 1221, 90};

    for (int n : testCases)
    {
        cout << "Input: " << n << endl;
        cout << "Mirror Distance: " << obj.mirrorDistance(n) << endl;
        cout << "----------------------" << endl;
    }

    return 0;
}