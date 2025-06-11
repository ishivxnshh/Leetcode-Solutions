#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q;

    MyStack() { }

    void push(int x) {
        q.push(x);
        int qs = q.size();
        for (int i = 0; i < qs - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int p = q.front();
        q.pop();
        return p;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.size() == 0;
    }
};

// ---------------- Driver Code ----------------
int main() {
    MyStack* obj = new MyStack();

    obj->push(10);
    obj->push(20);
    obj->push(30);

    cout << "Top: " << obj->top() << endl;    // Output: 30
    cout << "Pop: " << obj->pop() << endl;    // Output: 30
    cout << "Top: " << obj->top() << endl;    // Output: 20
    cout << "Is Empty: " << (obj->empty() ? "Yes" : "No") << endl;  // Output: No

    delete obj;
    return 0;
}