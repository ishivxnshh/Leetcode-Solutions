#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> s1, s2;

    MyQueue() { }

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (!s2.empty()) {
            int num = s2.top();
            s2.pop();
            return num;
        }
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        int num = s2.top();
        s2.pop();
        return num;
    }

    int peek() {
        if (!s2.empty()) {
            return s2.top();
        }
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

// ---------------- Driver Code (DC) ----------------
int main() {
    MyQueue* obj = new MyQueue();

    obj->push(1);
    obj->push(2);
    obj->push(3);

    cout << "Peek: " << obj->peek() << endl;  // Output: 1
    cout << "Pop: " << obj->pop() << endl;    // Output: 1
    cout << "Peek: " << obj->peek() << endl;  // Output: 2
    cout << "Is Empty: " << (obj->empty() ? "Yes" : "No") << endl; // Output: No

    delete obj;
    return 0;
}