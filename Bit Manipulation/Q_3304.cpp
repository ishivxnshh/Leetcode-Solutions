#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    void operate(string &word)
    {
        string temp = "";
        for(auto ch : word)
        {
            if (ch == 'z') temp += 'a';
            else temp += char(int(ch) + 1);
        }
        word += temp;
    }

    char kthCharacter(int k) {
        /*
            Brute-Force Approach:
            Time Complexity: O(2^(logk) = k)
            Space Complexity: O(k))
        */
        // string word = "a";
        // for (int i = 0; i < k; i++)
        // {
        //     operate(word);
        //     if (word.length() >= k) break;
        // }
        // return word[k - 1];
        
        /*
            Optimized Approach:
            Time Complexity: O(k), where n is the number of operations.
            Space Complexity: O(1), as we do not construct the entire string.
        */
        int shift = __builtin_popcount(k - 1);
        return 'a' + shift;
    }
};

// Driver code
int main() {
    Solution sol;
    int k;

    cout << "Enter the value of k: ";
    cin >> k;

    char result = sol.kthCharacter(k);
    cout << "The " << k << "-th character in the generated string is: " << result << endl;

    return 0;
}
