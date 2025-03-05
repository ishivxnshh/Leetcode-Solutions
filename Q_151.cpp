#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {

        // Using extra space (time: O(n), space: O(n))
        int i = 0;
        string temp = "";
        vector<string> words;
        while (i < s.size())
        {
            if (s[i] == ' ' && i > 0 && s[i - 1] != ' ')
            {
                words.push_back(temp);
                temp = "";
            }
            else if (s[i] != ' ')
            {
                temp += s[i];
            }
            if (i == s.size() - 1 && !temp.empty())
            {
                words.push_back(temp);
            }
            i++;
        }
        temp = "";
        for (int i = words.size() - 1; i >= 0; i--)
        {
            temp += words[i];
            if (i > 0)
            {
                temp += ' ';
            }
        }
        return temp;

        // Two pointer approach (time: O(n), space: O(1))
        int left = 0, right = s.size() - 1;
        string ans = "", temp = "";
        while (left <= right && s[left] == ' ')
        {
            left++;
        }
        while (left <= right)
        {
            if (s[left] != ' ')
            {
                temp += s[left];
            }
            else if (!temp.empty())
            {
                if (!ans.empty())
                {
                    ans = temp + " " + ans;
                }
                else
                {
                    ans = temp;
                }
                temp = "";
            }
            left++;
        }
        if (!temp.empty())
        {
            if (!ans.empty())
            {
                ans = temp + " " + ans;
            }
            else
            {
                ans = temp;
            }
        }
        return ans;
    }
};

// Driver Code
int main()
{
    Solution solution;

    // Test cases
    string s1 = "the sky is blue";
    string s2 = "  hello world  ";
    string s3 = "a good   example";
    string s4 = "   ";
    string s5 = "singleword";

    cout << "Input: \"" << s1 << "\"\nOutput: \"" << solution.reverseWords(s1) << "\"\n\n";
    cout << "Input: \"" << s2 << "\"\nOutput: \"" << solution.reverseWords(s2) << "\"\n\n";
    cout << "Input: \"" << s3 << "\"\nOutput: \"" << solution.reverseWords(s3) << "\"\n\n";
    cout << "Input: \"" << s4 << "\"\nOutput: \"" << solution.reverseWords(s4) << "\"\n\n";
    cout << "Input: \"" << s5 << "\"\nOutput: \"" << solution.reverseWords(s5) << "\"\n\n";

    return 0;
}
