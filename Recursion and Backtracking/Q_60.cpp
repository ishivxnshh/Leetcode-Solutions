#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        int fact = 1;
        vector<int> numbers;

        for (int i = 1; i < n; i++)
        {
            fact *= i;
            numbers.push_back(i);
        }

        numbers.push_back(n);
        string ans = "";
        k = k - 1;

        while (true)
        {
            ans = ans + to_string(numbers[k / fact]);
            numbers.erase(numbers.begin() + k / fact);

            if (numbers.size() == 0)
            {
                break;
            }

            k %= fact;
            fact /= numbers.size();
        }

        return ans;
    }
};

// Driver Code
int main()
{
    Solution sol;

    int n1 = 3, k1 = 3;
    cout << "Test Case 1 - n = " << n1 << ", k = " << k1 << endl;
    cout << "Output: " << sol.getPermutation(n1, k1) << endl;

    int n2 = 4, k2 = 9;
    cout << "\nTest Case 2 - n = " << n2 << ", k = " << k2 << endl;
    cout << "Output: " << sol.getPermutation(n2, k2) << endl;

    int n3 = 1, k3 = 1;
    cout << "\nTest Case 3 - n = " << n3 << ", k = " << k3 << endl;
    cout << "Output: " << sol.getPermutation(n3, k3) << endl;

    return 0;
}