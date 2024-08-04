#include <iostream>
#include <string>
#include <cctype> // For isalnum() and tolower()

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int st = 0, end = s.size() - 1;
        while (st < end)
        {
            while (st < end && !isalnum(s[st]))
            {
                st++;
            }
            while (st < end && !isalnum(s[end]))
            {
                end--;
            }
            if (tolower(s[st]) != tolower(s[end]))
            {
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
};

int main()
{
    Solution sol;

    string test1 = "A man, a plan, a canal: Panama";
    string test2 = "race a car";
    string test3 = " ";

    cout << "Test Case 1: " << (sol.isPalindrome(test1) ? "True" : "False") << endl;
    cout << "Test Case 2: " << (sol.isPalindrome(test2) ? "True" : "False") << endl;
    cout << "Test Case 3: " << (sol.isPalindrome(test3) ? "True" : "False") << endl;

    return 0;
}
