#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int kthGrammar(int n, int k) {
        /*
        Time Complexity: O(n), where n is the row number. Each recursive call reduces n by 1.
        Space Complexity: O(n), due to the recursion stack.
        */
        if (n == 1 && k == 1) return 0;

        int len = pow(2, n - 1);
        int mid = len / 2;
        if (k <= mid) {
            return kthGrammar(n - 1, k);
        } else {
            return !(kthGrammar(n - 1, k - mid));
        }
    }
};

int main() {
    Solution sol;
    
    int n, k;
    cout << "Enter n and k: ";
    cin >> n >> k;

    int result = sol.kthGrammar(n, k);
    cout << "The " << k << "th symbol in row " << n << " is: " << result << endl;

    return 0;
}