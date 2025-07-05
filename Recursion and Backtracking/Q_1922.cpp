#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    long long power(int x, long long n) {
        if(n == 0)
            return 1;
        else if(n % 2 == 0) {
            long long y = power(x, n / 2);
            return (y * y) % MOD;
        }
        else
            return (x * power(x, n - 1)) % MOD;
    }

    int countGoodNumbers(long long n) {
        long long numberOfOddPlaces = n / 2;
        long long numberOfEvenPlaces = n / 2 + n % 2;
        return (power(5, numberOfEvenPlaces) * power(4, numberOfOddPlaces)) % MOD;
    }
};

// Driver Code
int main() {
    long long n;
    cout << "Enter n: ";
    cin >> n;

    Solution obj;
    cout << "Result: " << obj.countGoodNumbers(n) << endl;

    return 0;
}
