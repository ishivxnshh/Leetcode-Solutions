#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int M = 1e9 + 7;

    int numOfSubarrays(vector<int> &arr)
    {
        // bruteforce --> O(N^3)

        // int n = arr.size();
        // int count = 0;
        // for (int i=0 ; i<n ; i++){
        //     for (int j=0 ; j<n ; j++){
        //         int sum = 0;
        //         for (int k=i ; k<=j ; k++){
        //             sum += arr[k];
        //         }
        //         if (sum % 2 == 1) count++;
        //     }
        // }
        // return count;

        // better --> O(N^2)

        // int n = arr.size();
        // int count = 0;
        // for (int i=0 ; i<n ; i++){
        //     int sum = 0;
        //     for (int j=i ; j<n ; j++){
        //         sum += arr[j];
        //         if (sum % 2 == 1) count++;
        //     }
        // }
        // return count;

        // Optimal --> O(N)

        int n = arr.size();
        int count = 0;
        int oddcount = 0;
        int evencount = 1;
        int prefix_sum = 0;
        for (int i = 0; i < n; i++)
        {
            prefix_sum += arr[i];
            if (prefix_sum % 2 == 0)
            {
                // even + odd = odd
                count = (count + oddcount) % M;
                evencount++;
            }
            else
            {
                // odd + even = odd
                count = (count + evencount) % M;
                oddcount++;
            }
        }
        return count;
    }
};

// Driver Code
int main()
{
    Solution sol;

    vector<vector<int>> testCases = {
        {1, 3, 5},    // Expected output: 4
        {2, 4, 6},    // Expected output: 0
        {1, 2, 3, 4}, // Expected output: 4
        {1, 1, 1, 1}, // Expected output: 10
        {2, 1, 4, 3}  // Expected output: 6
    };

    for (int i = 0; i < testCases.size(); i++)
    {
        cout << "Test Case " << i + 1 << ": "
             << sol.numOfSubarrays(testCases[i]) << endl;
    }

    return 0;
}
