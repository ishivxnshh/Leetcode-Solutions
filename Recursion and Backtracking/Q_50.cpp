#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double recurse(double x, long long n)
    {
        if (n == 0)
        {
            return 1;
        }
        else if (n % 2 == 0)
        {
            double y = recurse(x, n / 2);
            return y * y;
        }
        else
        {
            return x * recurse(x, n - 1);
        }
    }

    double myPow(double x, int n)
    {
        long long nn = llabs((long long)n);
        double res = recurse(x, nn);

        if (n > 0)
        {
            return res;
        }
        else
        {
            return 1 / res;
        }
    }
};

int main()
{
    Solution obj;

    double x;
    int n;

    cin >> x >> n;

    cout << obj.myPow(x, n) << endl;

    return 0;
}
