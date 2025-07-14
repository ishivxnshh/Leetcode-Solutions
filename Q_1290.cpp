#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int result = 0;
        while (head) {
            result = (result << 1) | (head->val);
            head = head->next;
        }
        return result;
    }
};

// Driver code
int main() {
    // Create the linked list: 1 -> 0 -> 1 (binary 101)
    ListNode* node3 = new ListNode(1);
    ListNode* node2 = new ListNode(0, node3);
    ListNode* node1 = new ListNode(1, node2);
    ListNode* head = node1;

    Solution sol;
    int decimalValue = sol.getDecimalValue(head);

    cout << "Decimal Value: " << decimalValue << endl;

    // Clean up memory
    delete node1;
    delete node2;
    delete node3;

    return 0;
}