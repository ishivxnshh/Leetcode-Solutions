#include <iostream>
#include <stack>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    ListNode* reverse(ListNode* head)
    {
        if(head == NULL || head -> next == NULL)
            return head;
        ListNode* newHead = reverse(head -> next);
        ListNode* front = head -> next;
        front -> next = head;
        head -> next = NULL;
        return newHead;
    }
    
    bool isPalindrome(ListNode* head) {
        // Stack Based Approach (tc: O(n), sc: O(n))
        // stack<int> stk;
        // ListNode* temp = head;
        // while(temp != NULL) {
        //     stk.push(temp->val);
        //     temp = temp->next;
        // }
        // temp = head;
        // while(temp != NULL) {
        //     if(temp->val != stk.top())
        //         return false;
        //     stk.pop();
        //     temp = temp->next;
        // }
        // return true;

        // Optimal Approach (Tortoise & Hare Approach) (TC: O(n), SC: O(1))
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast -> next != NULL && fast -> next -> next != NULL)
        {
            slow = slow -> next;
           fast = fast -> next -> next;
        }
        ListNode* newHead = reverse(slow -> next);
        ListNode* first = head;
        ListNode* second = newHead;
        while(second != NULL)
        {
            if(first -> val != second -> val)
            {
                reverse(newHead);
                return false;
            }
            first = first -> next;
            second = second -> next;
        }
        reverse(newHead);
        return true;
    }
};

/* Driver Code */
int main() {
    // Create a palindrome linked list: 1 -> 2 -> 3 -> 2 -> 1
    ListNode* node5 = new ListNode(1);
    ListNode* node4 = new ListNode(2, node5);
    ListNode* node3 = new ListNode(3, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* node1 = new ListNode(1, node2);

    Solution sol;
    bool result = sol.isPalindrome(node1);

    cout << "Is palindrome? " << (result ? "Yes" : "No") << endl;

    return 0;
}
