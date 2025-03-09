#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        // Brute Force Approach (Time Complexity: O(N sqrt N + O(NlogN) + O(N) ≈ O(N sqrtN) | Space Complexity: O(N))
        // map<pair<int, int>, int> mpp;
        // int a = -1;
        // int mini = -1;
        // for (int i = left; i <= right; i++) {
        //     int count = 0;
        //     if (i > 1) {
        //         for (int j = 2; j * j <= i; j++) {
        //             if (i % j == 0) {
        //                 count++;
        //                 break;
        //             }
        //         }
        //     } else {
        //         count = 1;
        //     }
        //     if (count == 0) {
        //         if (a == -1) {
        //             a = i;
        //         } else {
        //             mpp[{a, i}] = i - a;
        //             if (mini == -1)
        //                 mini = i - a;
        //             else
        //                 mini = min(mini, i - a);
        //             a = i;
        //         }
        //     }
        // }
        // for (auto it : mpp)
        //     if (it.second == mini)
        //         return {it.first.first, it.first.second};
        // return {-1, -1};


        
    }
};

// Driver Code
int main() {
    Solution obj;
    
    // Test cases
    vector<pair<int, int>> testCases = {
        {10, 30},
        {1, 10},
        {50, 100},
        {2, 50},
        {90, 110}
    };

    for (auto& test : testCases) {
        int left = test.first, right = test.second;
        vector<int> result = obj.closestPrimes(left, right);
        cout << "Closest primes between " << left << " and " << right << " : ";
        if (result[0] == -1) {
            cout << "No prime pair found";
        } else {
            cout << result[0] << " " << result[1];
        }
        cout << endl;
    }

    return 0;
}