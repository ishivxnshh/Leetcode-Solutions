#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<char> vec;
        int wrong = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                vec.push_back(s1[i]);
                vec.push_back(s2[i]);
                wrong++;
            }
            if (wrong > 2)
                return false;
        }
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] != vec[vec.size() - i - 1])
                return false;
        }
        return true;
    }
};

int main() {
    Solution solution;

    // Test Case 1
    string s1 = "bank";
    string s2 = "kanb";
    cout << "Test Case 1: " << (solution.areAlmostEqual(s1, s2) ? "true" : "false") << endl;

    // Test Case 2
    string s3 = "attack";
    string s4 = "defend";
    cout << "Test Case 2: " << (solution.areAlmostEqual(s3, s4) ? "true" : "false") << endl;

    // Test Case 3
    string s5 = "kelb";
    string s6 = "kelb";
    cout << "Test Case 3: " << (solution.areAlmostEqual(s5, s6) ? "true" : "false") << endl;

    return 0;
}
