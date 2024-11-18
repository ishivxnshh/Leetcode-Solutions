#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        int a = 0;
        int b = sqrt(c);
        while (a <= b) {
            long sum = static_cast<long>(a) * a + static_cast<long>(b) * b;
            if (sum == c) {
                return true;
            } else if (sum > c) {
                b--;
            } else {
                a++;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    int c;

    // Prompt user input
    cout << "Enter an integer value for c: ";
    cin >> c;

    // Call the judgeSquareSum function and display the result
    if (solution.judgeSquareSum(c)) {
        cout << "Yes, " << c << " can be expressed as the sum of two squares." << endl;
    } else {
        cout << "No, " << c << " cannot be expressed as the sum of two squares." << endl;
    }

    // Optional: Test with some predefined values
    cout << "\nTesting with predefined values:\n";
    int testCases[] = {0, 1, 2, 5, 10, 25, 41};
    for (int test : testCases) {
        cout << "c = " << test << ": " 
             << (solution.judgeSquareSum(test) ? "True" : "False") << endl;
    }

    return 0;
}
