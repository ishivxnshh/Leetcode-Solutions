#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        if (n == 2) return "11";
        string a = "11";
        for (int i = 3; i <= n; i++) {
            string b = "";
            int count = 1;
            for (int j = 1; j < a.length(); j++) {
                if (a[j] == a[j - 1]) {
                    count++;
                } else {
                    b += to_string(count) + a[j - 1];
                    count = 1;
                }
            }
            b += to_string(count) + a.back();
            a = b;
        }
        return a;
    }
};

// Driver Code
int main() {
    Solution solution;

    // Test Case 1: n = 1
    int n1 = 1;
    cout << "The " << n1 << "st term is: " << solution.countAndSay(n1) << endl;

    // Test Case 2: n = 4
    int n2 = 4;
    cout << "The " << n2 << "th term is: " << solution.countAndSay(n2) << endl;

    // Test Case 3: n = 5
    int n3 = 5;
    cout << "The " << n3 << "th term is: " << solution.countAndSay(n3) << endl;

    return 0;
}
