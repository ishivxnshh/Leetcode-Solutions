#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int start = 0, end = s.size() - 1;
        while (start < end)
        {
            swap(s[start++], s[end--]);
        }
    }
};

void printVector(const vector<char> &s)
{
    for (char c : s)
    {
        cout << c << " ";
    }
    cout << endl;
}

int main()
{
    Solution solution;

    // Test case 1
    vector<char> test1 = {'h', 'e', 'l', 'l', 'o'};
    cout << "Original: ";
    printVector(test1);
    solution.reverseString(test1);
    cout << "Reversed: ";
    printVector(test1);

    // Test case 2
    vector<char> test2 = {'H', 'a', 'n', 'n', 'a', 'h'};
    cout << "Original: ";
    printVector(test2);
    solution.reverseString(test2);
    cout << "Reversed: ";
    printVector(test2);

    return 0;
}


// USING RECURSION 

// void abcd(int i, int j, vector<char>& s)
// {
//     if(i >= j)
//         return;
//     swap(s[i], s[j]);
//     abcd(i + 1, j - 1, s);
// }
// void reverseString(vector<char>& s) {
//     abcd(0, s.size() - 1, s);
// }