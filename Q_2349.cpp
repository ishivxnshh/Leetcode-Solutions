#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

class NumberContainers {
public:
    unordered_map<int, int> indextoNumber;
    unordered_map<int, set<int>> numbertoindex;
    
    void change(int index, int number) 
    {
        if (indextoNumber.find(index) != indextoNumber.end()) 
        {
            int oldNumber = indextoNumber[index];
            numbertoindex[oldNumber].erase(index);
        }
        indextoNumber[index] = number;
        numbertoindex[number].insert(index);
    }

    int find(int number) 
    {
        if (numbertoindex.find(number) != numbertoindex.end() && !numbertoindex[number].empty()) 
        {
            return *numbertoindex[number].begin();
        } 
        else 
        {
            return -1;
        }
    }
};

// Driver function to test the solution
int main() {
    NumberContainers nc;
    
    // Test cases
    nc.change(1, 10);
    nc.change(2, 20);
    nc.change(3, 10);
    cout << "find(10): " << nc.find(10) << endl; // Expected: 1
    cout << "find(20): " << nc.find(20) << endl; // Expected: 2
    cout << "find(30): " << nc.find(30) << endl; // Expected: -1
    
    nc.change(1, 30);
    cout << "find(10): " << nc.find(10) << endl; // Expected: 3
    cout << "find(30): " << nc.find(30) << endl; // Expected: 1
    
    return 0;
}
