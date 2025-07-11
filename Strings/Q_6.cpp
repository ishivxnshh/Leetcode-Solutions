#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> str(numRows, "");
        int i = 0;
        while(i < s.length())
        {
            for (int index = 0; index < numRows; index++)
            {
                if (i >= s.length()) break; 
                str[index] += s[i++];
            }
            for (int index = numRows - 2; index > 0; index--)
            {
                if (i >= s.length()) break; 
                str[index] += s[i++];
            }
        }
        string res = "";
        for (auto st : str)
            res += st;
        return res;
    }
};

// Driver Code
int main() {
    Solution sol;
    string s = "PAYPALISHIRING";
    int numRows = 3;

    string result = sol.convert(s, numRows);
    cout << "Zigzag Conversion: " << result << endl;

    return 0;
}