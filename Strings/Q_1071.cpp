#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int GCD(int a, int b)
    {
        while (a % b != 0)
        {
            int r = a % b;
            a = b;
            b = r;
        }
        return b;
    }

    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        int a = str1.length();
        int b = str2.length();
        int gcd = GCD(a, b);
        return str1.substr(0, gcd);
    }
};

int main() {
    Solution sol;
    
    // Sample Test Cases
    string str1 = "ABCABC";
    string str2 = "ABC";
    cout << "GCD of strings: " << sol.gcdOfStrings(str1, str2) << endl;

    str1 = "ABABAB";
    str2 = "ABAB";
    cout << "GCD of strings: " << sol.gcdOfStrings(str1, str2) << endl;

    str1 = "LEET";
    str2 = "CODE";
    cout << "GCD of strings: " << sol.gcdOfStrings(str1, str2) << endl;

    return 0;
}