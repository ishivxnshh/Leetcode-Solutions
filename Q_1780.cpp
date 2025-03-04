#include <bits/stdc++.h>

using namespace std;

class Solution 
{
public:
    // ✅ Optimized Approach (Base-3 Representation) [O(log n) Time, O(1) Space]
    bool checkPowersOfThreeOptimized(int n) 
    {
        while (n > 0) 
        {
            if (n % 3 == 2)  // If any digit in base-3 representation is '2', return false
                return false;
            n /= 3;
        }
        return true;
    }

    // 🔴 Your Original Approach (Checking with Distinct Powers of 3)
    bool checkPowersOfThree(int n) 
    {
        for (int i = 16; i >= 0; i--)  // 3^16 is large enough for any reasonable n
        {
            if (n > 0) 
            {
                if (pow(3, i) <= n)
                    n -= pow(3, i);
            } 
            else
                break;
        }
        if (n == 0)
            return true;
        else
            return false;
    }
};

// Driver Code
int main() 
{
    Solution obj;
    
    vector<int> testCases = {12, 91, 21, 27, 3, 30};

    cout << "Using Original Approach (Subtracting Powers of 3):\n";
    for (int n : testCases) 
    {
        cout << "n = " << n << " => " 
             << (obj.checkPowersOfThree(n) ? "True" : "False") << endl;
    }

    cout << "\nUsing Optimized Approach (Base-3 Representation):\n";
    for (int n : testCases) 
    {
        cout << "n = " << n << " => " 
             << (obj.checkPowersOfThreeOptimized(n) ? "True" : "False") << endl;
    }

    return 0;
}