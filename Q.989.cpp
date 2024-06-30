#include <iostream>
#include <vector>
#include <algorithm> // for reverse
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> res;
        int carry = 0;
        int i = num.size() - 1;
        
        while (i >= 0 || k > 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) {
                sum += num[i];
                i--;
            }
            if (k > 0) {
                sum += k % 10;
                k /= 10;
            }
            res.push_back(sum % 10);
            carry = sum / 10;
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution solution;
    
    // Example usage
    vector<int> num = {1, 2, 0, 0};
    int k = 34;
    
    vector<int> result = solution.addToArrayForm(num, k);
    
    // Print the result
    cout << "Result: ";
    for (int digit : result) {
        cout << digit << " ";
    }
    cout << endl;
    
    return 0;
}
