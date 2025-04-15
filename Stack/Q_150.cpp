#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> st;

        for (const string& token : tokens)
        {
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                if (token == "+")
                {
                    st.push(a + b);
                }
                else if (token == "-")
                {
                    st.push(a - b);
                }
                else if (token == "*")
                {
                    st.push(a * b);
                }
                else if (token == "/")
                {
                    st.push(a / b); // Truncates towards zero
                }
            }
            else
            {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};


// Driver code
int main()
{
    Solution solution;

    vector<string> tokens1 = {"2", "1", "+", "3", "*"};               // (2 + 1) * 3 = 9
    vector<string> tokens2 = {"4", "13", "5", "/", "+"};              // 4 + (13 / 5) = 6
    vector<string> tokens3 = {"10", "6", "9", "3", "/", "-", "*"};    // 10 * (6 - 3) = 30

    cout << "Result 1: " << solution.evalRPN(tokens1) << endl;
    cout << "Result 2: " << solution.evalRPN(tokens2) << endl;
    cout << "Result 3: " << solution.evalRPN(tokens3) << endl;

    return 0;
}