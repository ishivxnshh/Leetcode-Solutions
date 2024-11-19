#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {

        // Brute-Force Approach(TLE, TC: M*N, SC:1)
        // int count = 0;
        // for (auto st : message) {
        //     if (check(st, bannedWords))
        //         count++;
        //     if (count >= 2)
        //         return true;
        // }
        // return false;

        // 
    }

    bool check(string s, vector<string>& arr) {
        for (auto it : arr) {
            if (s == it)
                return true;
        }
        return false;
    }
};

int main() {
    // Example Input
    vector<string> message = {"hello", "discount", "offer", "spam"};
    vector<string> bannedWords = {"spam", "offer"};

    // Create an instance of the Solution class
    Solution solution;

    // Call the reportSpam method
    bool isSpam = solution.reportSpam(message, bannedWords);

    // Output the result
    if (isSpam) {
        cout << "The message is spam." << endl;
    } else {
        cout << "The message is not spam." << endl;
    }

    return 0;
}
