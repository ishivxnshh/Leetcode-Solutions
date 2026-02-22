#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) {
            return false;
        }
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    int countSetBits(int n) {
        int count = 0;

        while (n > 0) {
            if (n & 1) {
                count++;
            }
            n = n >> 1;
        }
        return count;
    }

    int countPrimeSetBits(int left, int right) {
        int result = 0;

        for (int i = left; i <= right; i++) {
            int bits = countSetBits(i);

            if (isPrime(bits)) {
                result++;
            }
        }

        return result;
    }
};

int main() {

    Solution obj;

    // Predefined Test Cases
    vector<pair<int,int>> testCases = {
        {6, 10},
        {10, 15},
        {1, 5},
        {842, 888},
        {1000, 1024}
    };

    for (int i = 0; i < testCases.size(); i++) {
        int left = testCases[i].first;
        int right = testCases[i].second;

        cout << "Test Case " << i + 1 << " (" 
             << left << ", " << right << ") -> ";

        cout << obj.countPrimeSetBits(left, right) << endl;
    }

    return 0;
}
