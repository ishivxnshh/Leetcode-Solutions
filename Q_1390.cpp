#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums)
    {
        int totalSum = 0;

        for (int x : nums)
        {
            int count = 0;
            int sum = 0;

            for (int d = 1; d <= sqrt(x); d++)
            {
                if (x % d == 0)
                {
                    int other = x / d;

                    if (other == d)
                    {
                        count++;
                        sum += d;
                    }
                    else
                    {
                        count += 2;
                        sum += d;
                        sum += other;
                    }
                }

                if (count > 4)
                    break;
            }

            if (count == 4)
            {
                totalSum += sum;
            }
        }

        return totalSum;
    }
};

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution obj;
    int result = obj.sumFourDivisors(nums);

    cout << "Sum of divisors of numbers having exactly 4 divisors: ";
    cout << result << endl;

    return 0;
}
