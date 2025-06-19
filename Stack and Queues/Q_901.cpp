// Time Complexity: O(1) amortized per call
// Space Complexity: O(N), where N is the number of calls to next()

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class StockSpanner
{
public:
    stack<pair<int, int>> stk;
    StockSpanner() {}
    int next(int price)
    {
        int span = 1;
        while (!stk.empty() && stk.top().first <= price)
        {
            span += stk.top().second;
            stk.pop();
        }
        stk.push({price, span});
        return span;
    }
};

// Driver Code (dc)
int main()
{
    StockSpanner* obj = new StockSpanner();
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    for (int price : prices)
    {
        cout << obj->next(price) << " ";
    }
    delete obj;
    return 0;
}