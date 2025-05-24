#include <iostream>
#include <map>
using namespace std;

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/* Solution Class */
class Solution {
public:
    /*
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    ListNode *detectCycle(ListNode *head) {
        // Brute-Force Approach  (TC: O(n * 2*logn), SC: O(n))
        // map<ListNode*, int> mpp;
        // ListNode* temp = head;
        // while (temp != NULL)
        // {
        //     if (mpp.find(temp) != mpp.end())
        //         return temp;  // Node where cycle begins
        //     mpp[temp] = 1;
        //     temp = temp->next;
        // }
        // return NULL;
        
        // Optimal Approach (Tortoise & Hare Approach) (TC: O(n), SC: O(1))
        
    }
};

/* Driver Code */
int main() {
    // Creating a cycle linked list: 1 -> 2 -> 3 -> 4 -> 2 (cycle)
    ListNode* node4 = new ListNode(4);
    ListNode* node3 = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node1 = new ListNode(1);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; // cycle starts at node2

    Solution sol;
    ListNode* startNode = sol.detectCycle(node1);
    if (startNode)
        cout << "Cycle starts at node with value: " << startNode->val << endl;
    else
        cout << "No cycle detected." << endl;

    // Breaking the cycle and testing again
    node4->next = nullptr;
    startNode = sol.detectCycle(node1);
    if (startNode)
        cout << "Cycle starts at node with value: " << startNode->val << endl;
    else
        cout << "No cycle detected after breaking." << endl;

    return 0;
}