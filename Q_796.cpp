#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        
        // (tc: n^2, sc: 1)
        // if(s.length()!=goal.length())
        //     return false;
        // for(int i=0;i<goal.size();i++)
        // {
        //     rotate(goal.begin(), goal.begin()+1, goal.end());
        //     if(goal==s)
        //         return true;
        // }
        // return false;

        // (tc: n, sc: 1)
        return (s.length() == goal.length() && (s + s).find(goal) != string::npos);
    }
};

// Driver Code
int main() {
    Solution sol;
    
    // Sample Test Cases
    cout << boolalpha; // Print 'true'/'false' instead of '1'/'0'
    cout << sol.rotateString("abcde", "cdeab") << endl; // true
    cout << sol.rotateString("abcde", "abced") << endl; // false

    return 0;
}
