#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (s.length() != 0 && s.find(part) < s.length()) {
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};

int main() {
    Solution solution;

    // Test case 1
    string s1 = "daabcbaabcbc";
    string part1 = "abc";
    string result1 = solution.removeOccurrences(s1, part1);
    cout << "Test case 1 - Expected: dab, Got: " << result1 << endl;

    // Test case 2
    string s2 = "axxxxyyyyb";
    string part2 = "xy";
    string result2 = solution.removeOccurrences(s2, part2);
    cout << "Test case 2 - Expected: ab, Got: " << result2 << endl;

    // Test case 3
    string s3 = "aaaaa";
    string part3 = "aa";
    string result3 = solution.removeOccurrences(s3, part3);
    cout << "Test case 3 - Expected: a, Got: " << result3 << endl;

    // Test case 4
    string s4 = "abcd";
    string part4 = "e";
    string result4 = solution.removeOccurrences(s4, part4);
    cout << "Test case 4 - Expected: abcd, Got: " << result4 << endl;

    // Test case 5
    string s5 = "";
    string part5 = "a";
    string result5 = solution.removeOccurrences(s5, part5);
    cout << "Test case 5 - Expected: , Got: " << result5 << endl;

    return 0;
}
