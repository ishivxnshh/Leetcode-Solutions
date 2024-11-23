#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            while ((s[left] != 'a' && s[left] != 'e' && s[left] != 'i' &&
                    s[left] != 'o' && s[left] != 'u' && s[left] != 'A' &&
                    s[left] != 'E' && s[left] != 'I' && s[left] != 'O' &&
                    s[left] != 'U') &&
                   left < right) {
                left++;
            }
            while ((s[right] != 'a' && s[right] != 'e' && s[right] != 'i' &&
                    s[right] != 'o' && s[right] != 'u' && s[right] != 'A' &&
                    s[right] != 'E' && s[right] != 'I' && s[right] != 'O' &&
                    s[right] != 'U') &&
                   left < right) {
                right--;
            }
            if (left < right) {
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                left++;
                right--;
            }
        }
        return s;
    }
};

int main() {
    Solution solution;

    // Test Case 1
    string input1 = "hello";
    string result1 = solution.reverseVowels(input1);
    cout << "Input: " << input1 << "\nOutput: " << result1 << endl;

    // Test Case 2
    string input2 = "leetcode";
    string result2 = solution.reverseVowels(input2);
    cout << "Input: " << input2 << "\nOutput: " << result2 << endl;

    return 0;
}
