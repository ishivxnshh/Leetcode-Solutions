#include <iostream>
#include <vector>
#include <string>
using namespace std;

int finalValueAfterOperations(vector<string>& operations) {
    int X = 0;
    for (auto operation : operations) {
        if (operation == "++X" || operation == "X++") {
            X++;
        } else if (operation == "--X" || operation == "X--") {
            X--;
        }
    }
    return X;
}

int main() {
    vector<vector<string>> testCases = {
        {"--X", "X++", "X++"},
        {"++X", "++X", "X--"},
        {"X++", "X++", "X++"},
        {"--X", "--X", "--X"},
        {"++X", "X++", "--X"}
    };

    vector<int> expectedOutputs = {1, 1, 3, -3, 1};

    cout << "Executing predefined test cases...\n";

    for (int i = 0; i < testCases.size(); ++i) {
        int result = finalValueAfterOperations(testCases[i]);
        cout << "Test Case " << i + 1 << ":\n";
        cout << "Operations: ";
        for (string op : testCases[i]) {
            cout << op << " ";
        }
        cout << "\nExpected Output: " << expectedOutputs[i] << "\n";
        cout << "Actual Output: " << result << "\n";
        cout << (result == expectedOutputs[i] ? "Test Passed" : "Test Failed") << "\n";
        cout << "--------------------------\n";
    }

    return 0;
}
