#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> res;

    void generate(string s, int open, int close, int n) {
        if (open > n || close > open)
            return;
        if (open == n && close == n) {
            res.push_back(s);
            return;
        }
        generate(s + '(', open + 1, close, n);
        generate(s + ')', open, close + 1, n);
    }

    vector<string> generateParenthesis(int n) {
        res.clear(); // Ensuring res is empty for each call
        generate("", 0, 0, n);
        return res;
    }
};

// Driver Code
int main() {
    Solution sol;
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<string> result = sol.generateParenthesis(n);

    cout << "Generated Parentheses Combinations:\n";
    for (const string &s : result) {
        cout << s << endl;
    }

    return 0;
}
