#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        /*
            Brute-Force Approach:
            Time Complexity: O(k^2)
            Space Complexity: O(k))
        */
        // string word = "a";
        // for (int i = 0; i < operations.size(); i++) {
        //     if (operations[i] == 0) {
        //         word += word; // Duplicate the current word
        //     } else {
        //         string temp = "";
        //         for (char ch : word) {
        //             if (ch == 'z') temp += 'a';
        //             else temp += char(int(ch) + 1); // Increment char
        //         }
        //         word += temp;
        //     }
        //     if (word.length() >= k) break;
        // }
        // return word[k - 1];

        /*
            Optimal Approach:
            Time Complexity: O(log k)
            Space Complexity: O(1)
        */
       if (k == 1) return 'a';

        int n = operations.size();
        long long len = 1;
        long long newK = -1;
        int operationType = -1;

        for (int i = 0; i < n; i++)
        {
            len *= 2;
            if (len >= k)
            {
                operationType = operations[i];
                newK = k - len / 2;
                break;
            }
        }
        
        char ch = kthCharacter(newK, operations);

        if (operationType == 0) return ch;
        else return ch == 'z' ? 'a' : ch + 1;
    }
};

// Driver code
int main() {
    Solution sol;
    long long k;
    int n;

    cout << "Enter the value of k: ";
    cin >> k;

    cout << "Enter number of operations: ";
    cin >> n;

    vector<int> operations(n);
    cout << "Enter operations (0 for duplicate, 1 for increment): ";
    for (int i = 0; i < n; i++) {
        cin >> operations[i];
    }

    char result = sol.kthCharacter(k, operations);
    cout << "The " << k << "-th character is: " << result << endl;

    return 0;
}