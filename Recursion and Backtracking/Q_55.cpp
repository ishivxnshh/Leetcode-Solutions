/*
Time Complexity: O(log n)
Space Complexity: O(log n) (due to recursion)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    double powernikalo(double x, long long n)
    {
        if (n == 0)
            return 1;
        else if (n % 2 == 0)
        {
            double y = powernikalo(x, n / 2);
            return y * y;
        }
        else
            return x * powernikalo(x, n - 1);
    }

    double myPow(double x, int n) {
        long long nn = n;
        double res = powernikalo(x, abs(nn));
        return (n > 0) ? res : 1 / res;
    }
};

// Driver Code
int main() {
    Solution obj;
    
    // Sample Test Cases
    cout << "2^10 = " << obj.myPow(2.0, 10) << endl;      // Expected: 1024
    cout << "2^-2 = " << obj.myPow(2.0, -2) << endl;      // Expected: 0.25
    cout << "3^5 = " << obj.myPow(3.0, 5) << endl;        // Expected: 243
    cout << "1.5^3 = " << obj.myPow(1.5, 3) << endl;      // Expected: 3.375
    cout << "2^0 = " << obj.myPow(2.0, 0) << endl;        // Expected: 1
    cout << "0^5 = " << obj.myPow(0.0, 5) << endl;        // Expected: 0
    cout << "5^-3 = " << obj.myPow(5.0, -3) << endl;      // Expected: 0.008

    return 0;
}