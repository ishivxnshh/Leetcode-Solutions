#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* deleteMiddle(ListNode* head)
    {
        // Brute-Force Approach (counting first) (tc: O[n + n/2], sc: o[1])

        // Optimal Approach (Tortoise & Hare Approach) (TC: O(n/2) SC: O(1))
        if(head == NULL || head -> next == NULL)
            return NULL;
        ListNode* slow = head;
        ListNode* fast = head -> next -> next;
        while(fast != NULL && fast -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* del = slow -> next;
        slow -> next = slow -> next -> next;
        delete del;
        return head;
    }
};

// Helper function to print the linked list
void printList(ListNode* head)
{
    while (head != NULL)
    {
        cout << head->val;
        if (head->next != NULL)
        {
            cout << " -> ";
        }
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(int arr[], int size)
{
    if (size == 0)
    {
        return nullptr;
    }

    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;

    for (int i = 1; i < size; i++)
    {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
}

int main()
{
    Solution sol;

    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = createList(arr, size);

    cout << "Original List: ";
    printList(head);

    head = sol.deleteMiddle(head);

    cout << "After Deleting Middle Node: ";
    printList(head);

    return 0;
}