#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class MinStack
{
public:
    /*
    Time Complexity:
    - push: O(1)
    - pop: O(1)
    - top: O(1)
    - getMin: O(1)

    Space Complexity:
    - O(2n), where n is the number of elements in the stack.
    */
    stack<pair<int, int>> stk;
    MinStack() { }
    void push(int val)
    {
        if (stk.empty())
        {
            stk.push({val, val});
        }
        else
        {
            stk.push({val, min(val, stk.top().second)});
        }
    }
    void pop()
    {
        stk.pop();
    }
    int top()
    {
        return stk.top().first;
    }
    int getMin()
    {
        return stk.top().second;
    }

    /*
    Time Complexity:
    - push: O(1)
    - pop: O(1)
    - top: O(1)
    - getMin: O(1)

    Space Complexity:
    - O(n), where n is the number of elements in the stack.
    */
    // stack<long long> stk;
    // long long mini = LLONG_MAX;
    // MinStack() {}
    // void push(int val)
    // {
    //     if (stk.empty())
    //     {
    //         mini = val;
    //         stk.push(val);
    //     }
    //     else
    //     {
    //         if (val > mini)
    //         {
    //             stk.push(val);
    //         }
    //         else
    //         {
    //             long long encoded = 2LL * val - mini;
    //             stk.push(encoded);
    //             mini = val;
    //         }
    //     }
    // }
    // void pop()
    // {
    //     if (stk.empty())
    //         return;
    //     long long x = stk.top();
    //     stk.pop();
    //     if (x < mini)
    //         mini = 2LL * mini - x;
    //     if (stk.empty())
    //         mini = LLONG_MAX;
    // }
    // int top()
    // {
    //     if (stk.empty())
    //         return -1;
    //     long long x = stk.top();
    //     if (x < mini)
    //         return (int)mini;
    //     return (int)x;
    // }
    // int getMin()
    // {
    //     if (stk.empty())
    //         return -1;
    //     return (int)mini;
    // }
};

// ------------------------
// ✅ Driver Code for VS Code
// ------------------------

int main()
{
    MinStack *obj = new MinStack();

    obj->push(3);
    obj->push(5);
    cout << "Current Min: " << obj->getMin() << endl; // 3

    obj->push(2);
    obj->push(1);
    cout << "Current Min: " << obj->getMin() << endl; // 1

    obj->pop();
    cout << "Top Element: " << obj->top() << endl;    // 2
    cout << "Current Min: " << obj->getMin() << endl; // 2

    obj->pop();
    cout << "Top Element: " << obj->top() << endl;    // 5
    cout << "Current Min: " << obj->getMin() << endl; // 3

    delete obj;

    return 0;
}