#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string largestOddNumber(string num)
    {
        for (int i = num.length() - 1; i >= 0; i--)
        {
            if ((num[i] - '0') % 2 == 1)
            {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};

// Driver Code
int main()
{
    Solution solution;

    // Test cases
    string testCases[] = {"35427", "4206", "123456789", "24680", "95713", "987654322"};
    
    for (string num : testCases)
    {
        cout << "Input: \"" << num << "\"\n";
        cout << "Largest Odd Number: \"" << solution.largestOddNumber(num) << "\"\n\n";
    }

    return 0;
}
