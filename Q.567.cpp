#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    bool checkEqual(int a[26], int b[26]) {
        for(int i = 0; i < 26; i++) {
            if(a[i] != b[i])
                return false;
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        // character count array
        int count1[26] = {0};
        for(int i = 0; i < s1.length(); i++) {
            int index = s1[i] - 'a';
            count1[index]++;
        }

        // traverse s2 string in window of size s1 length and compare
        int i = 0;
        int windowSize = s1.length();
        int count2[26] = {0};

        // running for first window
        while(i < windowSize && i < s2.length()) {
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }
        if(checkEqual(count1, count2))
            return true;

        while(i < s2.length()) {
            char newchar = s2[i];
            int index = newchar - 'a';
            count2[index]++;
            char oldchar = s2[i - windowSize];
            index = oldchar - 'a';
            count2[index]--;
            if(checkEqual(count1, count2))
                return true;
            i++;
        }
        return false;
    }
};

int main() {
    Solution solution;

    // Test case 1
    string s1 = "ab";
    string s2 = "eidbaooo";
    bool result1 = solution.checkInclusion(s1, s2);
    cout << "Test case 1 - Expected: true, Got: " << (result1 ? "true" : "false") << endl;

    // Test case 2
    string s1_2 = "ab";
    string s2_2 = "eidboaoo";
    bool result2 = solution.checkInclusion(s1_2, s2_2);
    cout << "Test case 2 - Expected: false, Got: " << (result2 ? "true" : "false") << endl;

    return 0;
}
