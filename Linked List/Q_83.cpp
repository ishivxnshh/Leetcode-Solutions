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
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode* temp = head;
        while (temp != NULL && temp->next != NULL)
        {
            if (temp->val == temp->next->val)
            {
                temp->next = temp->next->next; // skip duplicate
            }
            else
            {
                temp = temp->next; // move forward
            }
        }
        return head;
    }
};

// Utility function to create linked list from vector
ListNode* createList(const vector<int>& arr)
{
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (size_t i = 1; i < arr.size(); i++)
    {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Utility function to print linked list
void printList(ListNode* head)
{
    while (head != nullptr)
    {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Solution sol;

    // Test case 1
    vector<int> arr1 = {1, 1, 2, 3, 3};
    ListNode* head1 = createList(arr1);
    cout << "Original List: ";
    printList(head1);

    head1 = sol.deleteDuplicates(head1);
    cout << "After Removing Duplicates: ";
    printList(head1);

    // Test case 2
    vector<int> arr2 = {1, 1, 1, 2, 2, 3};
    ListNode* head2 = createList(arr2);
    cout << "\nOriginal List: ";
    printList(head2);

    head2 = sol.deleteDuplicates(head2);
    cout << "After Removing Duplicates: ";
    printList(head2);

    return 0;
}