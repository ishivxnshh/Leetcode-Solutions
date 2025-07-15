#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution
{
public:
    bool isValid(string word)
    {
        if (word.size() < 3)
        {
            return false;
        }

        bool has_vowel = false;
        bool has_consonant = false;

        for (auto c : word)
        {
            if (isalpha(c))
            {
                c = tolower(c);
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                {
                    has_vowel = true;
                }
                else
                {
                    has_consonant = true;
                }
            }
            else if (!isdigit(c))
            {
                return false;
            }
        }

        return has_vowel && has_consonant;
    }
};

// ------------------ Driver Code ------------------
int main()
{
    Solution obj;

    // Sample test cases
    string test1 = "a1b";       // Valid: has both vowel and consonant
    string test2 = "123";       // Invalid: no vowel or consonant
    string test3 = "AE9";       // Invalid: no consonant
    string test4 = "bcd";       // Invalid: no vowel
    string test5 = "aB1#";      // Invalid: contains special char

    cout << boolalpha; // print 'true' or 'false' instead of 1/0

    cout << "Test1: " << obj.isValid(test1) << endl;
    cout << "Test2: " << obj.isValid(test2) << endl;
    cout << "Test3: " << obj.isValid(test3) << endl;
    cout << "Test4: " << obj.isValid(test4) << endl;
    cout << "Test5: " << obj.isValid(test5) << endl;

    return 0;
}