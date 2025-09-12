#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* insertionSortList(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* dummy = new ListNode(0);  // Dummy node
        dummy->next = head;
        ListNode* sortedTail = head;
        ListNode* curr = head->next;

        while (curr != NULL)
        {
            if (sortedTail->val <= curr->val)
            {
                // Case 1: already in order
                sortedTail = curr;
                curr = curr->next;
            }
            else
            {
                // Case 2: needs reinsertion
                ListNode* prev = dummy;
                while (prev->next->val <= curr->val)
                {
                    prev = prev->next;
                }

                // Reinsert curr between prev and prev->next
                sortedTail->next = curr->next;
                curr->next = prev->next;
                prev->next = curr;
                curr = sortedTail->next;
            }
        }
        return dummy->next;
    }
};

// -------- DRIVER CODE --------
void printList(ListNode* head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Example 1: [4, 2, 1, 3]
    ListNode* n4 = new ListNode(3);
    ListNode* n3 = new ListNode(1, n4);
    ListNode* n2 = new ListNode(2, n3);
    ListNode* n1 = new ListNode(4, n2);

    Solution s;
    ListNode* sortedHead = s.insertionSortList(n1);

    cout << "Sorted List: ";
    printList(sortedHead);

    // Example 2: [10, 5, 8]
    ListNode* m3 = new ListNode(8);
    ListNode* m2 = new ListNode(5, m3);
    ListNode* m1 = new ListNode(10, m2);

    ListNode* sortedHead2 = s.insertionSortList(m1);

    cout << "Sorted List: ";
    printList(sortedHead2);

    return 0;
}