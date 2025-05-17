#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

// Helper function to print the linked list
void printList(ListNode *head)
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
    // Creating the linked list: 4 -> 5 -> 1 -> 9
    ListNode *head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    cout << "Original List: ";
    printList(head);

    // Node to be deleted (e.g., node with value 5)
    Solution sol;
    sol.deleteNode(head->next); // Deletes the node with value 5

    cout << "After Deletion: ";
    printList(head);

    // Freeing memory
    while (head != NULL)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
