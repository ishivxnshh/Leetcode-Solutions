#include <iostream>
using namespace std;

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
    ListNode *middleNode(ListNode *head)
    {
        // B-F Approach (TC: O(n + n/2) SC: O(1))
        // ListNode *temp = head;
        // int length = 0;

        // while (temp != nullptr)
        // {
        //     length++;
        //     temp = temp->next;
        // }

        // int mid = length / 2;
        // int i = 0;

        // while (i < mid)
        // {
        //     head = head->next;
        //     i++;
        // }
        // return head;

        // Optimal Approach (TC: O(n/2) SC: O(1))
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
};

// Helper function to print list from a given node
void printList(ListNode *node)
{
    while (node != nullptr)
    {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

int main()
{
    // Creating linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    ListNode *middle = sol.middleNode(head);

    cout << "Middle node onward: ";
    printList(middle);

    // Free memory
    while (head != nullptr)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}