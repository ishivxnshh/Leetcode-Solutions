#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    // Function to check if a number is "good"
    bool isGood(int num)
    {
        bool changed = false;

        // TC: O(log n) -> checking each digit
        // SC: O(1)

        while (num > 0)
        {
            int digit = num % 10;

            // invalid digits
            if (digit == 3 || digit == 4 || digit == 7)
            {
                return false;
            }

            // digits that change after rotation
            if (digit == 2 || digit == 5 || digit == 6 || digit == 9)
            {
                changed = true;
            }

            num /= 10;
        }

        return changed;
    }

    int rotatedDigits(int n)
    {
        int count = 0;

        // TC: O(n * log n)
        // SC: O(1)

        for (int i = 1; i <= n; i++)
        {
            if (isGood(i))
            {
                count++;
            }
        }

        return count;
    }
};

int main()
{
    Solution obj;

    int t;
    cin >> t;

    // TC: O(t * n * log n)
    // SC: O(1)

    while (t--)
    {
        int n;
        cin >> n;

        cout << obj.rotatedDigits(n) << endl;
    }

    return 0;
}