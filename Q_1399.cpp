#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int countLargestGroup(int n)
    {
        vector<int> sums(37);
        for (int i = 1; i <= n; ++i)
        {
            sums[digsum(i)]++;
        }

        int maxi = 0, count = 0;
        for (int i : sums)
        {
            if (i > maxi)
            {
                maxi = i;
                count = 1;
            }
            else if (i == maxi)
            {
                ++count;
            }
        }

        return count;
    }

    int digsum(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
};

// Driver Code
int main()
{
    Solution sol;

    // Sample Test Case 1
    int n1 = 13;
    cout << "Input: " << n1 << endl;
    cout << "Output: " << sol.countLargestGroup(n1) << endl;

    // Sample Test Case 2
    int n2 = 2;
    cout << "Input: " << n2 << endl;
    cout << "Output: " << sol.countLargestGroup(n2) << endl;

    return 0;
}
