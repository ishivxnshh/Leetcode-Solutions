#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isVowel(char ch, string &str)
    {
        if (str.find(ch) != string::npos)
            return true;
        else
            return false;
    }

    string sortVowels(string s)
    {
        string str = "AEIOUaeiou";
        unordered_map<char, int> mpp;

        // count vowel frequency
        for (char ch : s)
        {
            if (isVowel(ch, str))
                mpp[ch]++;
        }

        int j = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (isVowel(s[i], str))
            {
                while (j < str.size() && mpp[str[j]] == 0)
                {
                    j++;
                }
                s[i] = str[j];
                mpp[str[j]]--;
            }
        }
        return s;
    }
};

// Driver Code
int main()
{
    Solution obj;

    string s1 = "lEetcOde";
    cout << "Original: " << s1 << endl;
    cout << "After Sorting Vowels: " << obj.sortVowels(s1) << endl;

    string s2 = "mzabq";
    cout << "Original: " << s2 << endl;
    cout << "After Sorting Vowels: " << obj.sortVowels(s2) << endl;

    return 0;
}