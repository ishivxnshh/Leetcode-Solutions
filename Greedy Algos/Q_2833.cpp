#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        // TC: O(N)
        // SC: O(1)

        int l = 0, r = 0, u = 0;

        for (int i = 0; i < moves.size(); i++)
        {
            if (moves[i] == 'L') l++;
            else if (moves[i] == 'R') r++;
            else u++;  // '_'
        }

        if (l >= r) return l - r + u;
        else return r - l + u;
    }
};

int main()
{
    Solution obj;

    // Test Case 1
    string moves1 = "L_RL__R";
    cout << "Output 1: " << obj.furthestDistanceFromOrigin(moves1) << endl;
    // Expected: 5

    // Test Case 2
    string moves2 = "_R__L";
    cout << "Output 2: " << obj.furthestDistanceFromOrigin(moves2) << endl;
    // Expected: 3

    // Test Case 3
    string moves3 = "RRLL";
    cout << "Output 3: " << obj.furthestDistanceFromOrigin(moves3) << endl;
    // Expected: 0

    // Test Case 4 (edge case: all blanks)
    string moves4 = "____";
    cout << "Output 4: " << obj.furthestDistanceFromOrigin(moves4) << endl;
    // Expected: 4

    return 0;
}