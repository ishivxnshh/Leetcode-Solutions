#include <iostream>
#include <string>
using namespace std;


class Solution
{
public:
    // Helper function to check if a substring is a palindrome
    bool check(string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    // Returns the longest palindromic substring
    string longestPalindrome(string s)
    {
        // Brute - Force Approach (Time Complexity: O(n^3), Space Complexity: O(1))
        // for (int length = s.size(); length > 0; length--)
        // {
        //     for (int start = 0; start <= s.size() - length; start++)
        //     {
        //         if (check(s, start, start + length - 1))
        //             return s.substr(start, length);
        //     }
        // }
        // return "";

        // Better Approach: Expand Around Center (Time Complexity: O(n^2), Space Complexity: O(1))
        // ABRBADAADAB EBBABAD
        if(s.length() <= 1) return s;
        string lps = "";
        for(int i = 1; i < s.length(); i++)
        {
            // consider odd length
            int low = i;
            int high = i;
            while(s[low] == s[high])
            {
                low--;
                high++;
                if(low == -1 || high == s.length())
                    break;
            }
            string palindrome = s.substr(low + 1, high - low - 1);
            if(palindrome.length() > lps.length())
                lps = palindrome;
            
            // consider even length
            low = i - 1;
            high = i;
            while(s[low] == s[high])
            {
                low--;
                high++;
                if(low == -1 || high == s.length())
                    break;
            }
            palindrome = s.substr(low + 1, high - low - 1);
            if(palindrome.length() > lps.length())
                lps = palindrome;
        }
        return lps;
    }
};

// Driver code
int main()
{
    Solution obj;

    string s1 = "babad";
    string s2 = "cbbd";
    string s3 = "a";
    string s4 = "ac";

    cout << "Longest Palindrome in \"" << s1 << "\": " << obj.longestPalindrome(s1) << endl;
    cout << "Longest Palindrome in \"" << s2 << "\": " << obj.longestPalindrome(s2) << endl;
    cout << "Longest Palindrome in \"" << s3 << "\": " << obj.longestPalindrome(s3) << endl;
    cout << "Longest Palindrome in \"" << s4 << "\": " << obj.longestPalindrome(s4) << endl;

    return 0;
}