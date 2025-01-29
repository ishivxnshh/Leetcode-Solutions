#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.size() - 1;
        int count = 0;
        
        // Skip trailing spaces
        while (end >= 0 && s[end] == ' ') {
            end--;
        }
        
        // Count the characters of the last word
        while (end >= 0 && s[end] != ' ') {
            count++;
            end--;
        }
        
        return count;
    }
};

// Driver Code
int main() {
    Solution solution;

    // Test Case 1: String with multiple spaces at the end
    string s1 = "Hello World   ";
    cout << "The length of the last word is: " << solution.lengthOfLastWord(s1) << endl;

    // Test Case 2: String with no spaces
    string s2 = "Hello";
    cout << "The length of the last word is: " << solution.lengthOfLastWord(s2) << endl;

    // Test Case 3: String with only spaces
    string s3 = "   ";
    cout << "The length of the last word is: " << solution.lengthOfLastWord(s3) << endl;

    // Test Case 4: String with a single word and trailing spaces
    string s4 = "SingleWord   ";
    cout << "The length of the last word is: " << solution.lengthOfLastWord(s4) << endl;

    return 0;
}
