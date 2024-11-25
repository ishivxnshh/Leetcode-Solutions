#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int ansIndex = 0;
        int n = chars.size(); 

        while (i < n) {
            int j = i + 1;
            while (j < n && chars[i] == chars[j]) {
                j++;
            }

            // oldchar store
            chars[ansIndex++] = chars[i];
            int count = j - i;
            if (count > 1) {
                // converting count into single digits and saving in answer
                string cnt = to_string(count);
                for (char ch : cnt) {
                    chars[ansIndex++] = ch;
                }
            }
            i = j;
        }
        return ansIndex;
    }
};

void printVector(const vector<char>& chars, int length) {
    for (int i = 0; i < length; i++) {
        cout << chars[i];
    }
    cout << endl;
}

int main() {
    Solution solution;

    // Test case 1
    vector<char> chars1 = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int result1 = solution.compress(chars1);
    cout << "Test case 1 - Expected: a2b2c3, Got: ";
    printVector(chars1, result1);

    // Test case 2
    vector<char> chars2 = {'a'};
    int result2 = solution.compress(chars2);
    cout << "Test case 2 - Expected: a, Got: ";
    printVector(chars2, result2);

    // Test case 3
    vector<char> chars3 = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    int result3 = solution.compress(chars3);
    cout << "Test case 3 - Expected: ab12, Got: ";
    printVector(chars3, result3);

    return 0;
}
