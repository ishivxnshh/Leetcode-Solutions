#include <iostream>
using namespace std;

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* Solution Class */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Stack Based Approach
        // Iterative Approach (tc: O[n], sc; O[1])
    //     ListNode* prev = NULL;
    //     ListNode* temp = head;
    //     while (temp != NULL)
    //     {
    //         head = head->next;
    //         temp->next = prev;
    //         prev = temp;
    //         temp = head;
    //     }
    //     return prev;
    // }

    // Recursive Approach (tc: O[n], sc; O[n])
    if(head == NULL || head -> next == NULL)
            return head;
    ListNode* newHead = reverseList(head -> next);
    ListNode* front = head -> next;
    front -> next = head;
    head -> next = NULL;
    return newHead;
};

/* Function to print linked list */
void printList(ListNode* head)
{
    while (head != nullptr)
    {
        cout << head->val;
        if (head->next != nullptr)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

/* Driver Code */
int main()
{
    // Creating the linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* node5 = new ListNode(5);
    ListNode* node4 = new ListNode(4, node5);
    ListNode* node3 = new ListNode(3, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* head = new ListNode(1, node2);

    cout << "Original List: ";
    printList(head);

    // Reversing the list
    Solution sol;
    ListNode* reversedHead = sol.reverseList(head);

    cout << "Reversed List: ";
    printList(reversedHead);

    return 0;
}