#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int l = flowerbed.size();
        if (n == 0) return true;
        for (int i = 0; i < l; i++)
        {
            if (flowerbed[i] == 0)
            {
                bool leftEmpty = (i == 0) || (flowerbed[i - 1] == 0);
                bool rightEmpty = (i == l - 1) || (flowerbed[i + 1] == 0);
                if (leftEmpty && rightEmpty)
                {
                    flowerbed[i] = 1;
                    n--;
                    if (n == 0) return true;
                }
            }
        }
        return false;
    }
};

// Driver code
int main() {
    Solution sol;
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    int n = 1;

    bool result = sol.canPlaceFlowers(flowerbed, n);
    cout << (result ? "true" : "false") << endl;

    return 0;
}