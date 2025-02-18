#include <iostream>
#include <vector>
using namespace std;

class ProductOfNumbers {
private:
    vector<int> product;
    int size = 0;
public:
    ProductOfNumbers() {
        product.push_back(1);
        size = 0;
    }
    void add(int num) {
        if (num == 0) {
            product = {1};
            size = 0;
        } else {
            product.push_back(product[size] * num);
            size++;
        }
    }
    int getProduct(int k) {
        if (k > size) return 0;
        return product[size] / product[size - k];
    }
};

// Driver function to test the solution
int main() {
    ProductOfNumbers productOfNumbers;
    
    // Test cases
    productOfNumbers.add(3);
    productOfNumbers.add(0);
    productOfNumbers.add(2);
    productOfNumbers.add(5);
    productOfNumbers.add(4);
    
    cout << "getProduct(2): " << productOfNumbers.getProduct(2) << endl; // Expected: 20
    cout << "getProduct(3): " << productOfNumbers.getProduct(3) << endl; // Expected: 40
    cout << "getProduct(4): " << productOfNumbers.getProduct(4) << endl; // Expected: 0
    
    productOfNumbers.add(8);
    cout << "getProduct(2): " << productOfNumbers.getProduct(2) << endl; // Expected: 32
    
    return 0;
}