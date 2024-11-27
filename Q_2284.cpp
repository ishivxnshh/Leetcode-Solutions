#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> mpp;
        int maxi = INT_MIN;
        string max_string = "";
        for (int i = 0; i < messages.size(); i++) {
            int count = 0;
            string message = messages[i];
            for (auto ch : message) {
                if (ch == ' ') count += 1;
            }
            count += 1;
            mpp[senders[i]] += count;

            // If the current sender has sent more words, or if they tie but are
            // lexicographically larger
            if (mpp[senders[i]] > maxi || (mpp[senders[i]] == maxi && senders[i].compare(max_string) > 0)) {
                max_string = senders[i];
                maxi = mpp[senders[i]];
            }
        }
        return max_string;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<string> messages1 = {"Hello how are you", "I am good thanks", "What about you", "I am fine too"};
    vector<string> senders1 = {"Alice", "Bob", "Alice", "Bob"};
    cout << "Test Case 1 - Output: " << sol.largestWordCount(messages1, senders1) << ", Expected: Bob" << endl;

    // Test Case 2
    vector<string> messages2 = {"Good morning", "How are you doing today?", "It's a lovely day", "Enjoy your day!"};
    vector<string> senders2 = {"Charlie", "David", "Charlie", "David"};
    cout << "Test Case 2 - Output: " << sol.largestWordCount(messages2, senders2) << ", Expected: David" << endl;

    return 0;
}
