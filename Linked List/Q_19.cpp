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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        // Brute-Force Approach  (TC: O(n + (count - k)), SC: O(1))
        // ListNode* temp = head;
        // int count = 0;
        // while (temp != NULL)
        // {
        //     count++;
        //     temp = temp->next;
        // }
        // if (n == count)
        // {
        //     ListNode* newHead = head->next;
        //     delete head;
        //     return newHead;
        // }
        // temp = head;
        // int target = 0;
        // while (temp != NULL)
        // {
        //     if (target == (count - n - 1))
        //     {
        //         ListNode* del = temp->next;
        //         temp->next = temp->next->next;
        //         delete del;
        //         break;
        //     }
        //     temp = temp->next;
        //     target++;
        // }
        // return head;

        // Optimal Approach  (TC: O(n), SC: O(1))
        ListNode* fast = head;
        while(n--)
        {
            fast = fast -> next;
        }
        if(fast == NULL)
        {
            ListNode* newHead = head -> next;
            delete head;
            return newHead;
        }
        ListNode* slow = head;
        while(fast -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next;
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
    int n = 2;

    ListNode* head = createList(arr, sizeof(arr) / sizeof(arr[0]));

    cout << "Original List: ";
    printList(head);

    head = sol.removeNthFromEnd(head, n);

    cout << "After Removing " << n << "th Node from End: ";
    printList(head);

    return 0;
}
