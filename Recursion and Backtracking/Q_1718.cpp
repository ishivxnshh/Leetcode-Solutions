#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool generateSequence(vector<int> &result, vector<bool> &used, int n, int index)
    {
        if (index == result.size())
        {
            return true;
        }
        if (result[index] != 0)
        {
            return generateSequence(result, used, n, index + 1);
        }
        for (int num = n; num >= 1; num--)
        {
            if (used[num])
            {
                continue;
            }
            if (num == 1)
            {
                result[index] = 1;
                used[1] = true;
                if (generateSequence(result, used, n, index + 1))
                {
                    return true;
                }
                result[index] = 0;
                used[1] = false;
            }
            else
            {
                if (index + num < result.size() && result[index + num] == 0)
                {
                    result[index] = num;
                    result[index + num] = num;
                    used[num] = true;
                    if (generateSequence(result, used, n, index + 1))
                    {
                        return true;
                    }
                    result[index] = 0;
                    result[index + num] = 0;
                    used[num] = false;
                }
            }
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n)
    {
        vector<int> result(2 * n - 1, 0);
        vector<bool> used(n + 1, false);
        generateSequence(result, used, n, 0);
        return result;
    }
};

// Driver function to test the solution
int main()
{
    Solution sol;

    // Test cases
    vector<int> testCases = {3, 4, 5};

    for (int n : testCases)
    {
        vector<int> result = sol.constructDistancedSequence(n);
        cout << "n = " << n << " -> ";
        for (int num : result)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}