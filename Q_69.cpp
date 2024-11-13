#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int start = 0;
        int end = x;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (static_cast<long>(mid) * mid == x)
                return mid;
            else if (static_cast<long>(mid) * mid < x)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return end;
    }
};

int main() {
    Solution solution;
    int num;
    cout << "Enter a number to find its square root: ";
    cin >> num;
    int result = solution.mySqrt(num);
    cout << "The integer square root of " << num << " is " << result << endl;
    return 0;
}
