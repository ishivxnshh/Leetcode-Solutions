#include <iostream>
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
    ListNode* reverse(ListNode* temp)
    {
        if(temp == NULL || temp -> next == NULL)
            return temp;
        ListNode* newNode = reverse(temp -> next);
        ListNode* front = temp -> next;
        front -> next = temp;
        temp -> next = NULL;
        return newNode;
    }

    ListNode* findKthNode(ListNode* temp, int k)
    {
        k -= 1;
        while(temp != NULL && k > 0)
        {
            k--;
            temp = temp -> next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode  = NULL;
        while(temp != NULL)
        {
            ListNode* kthNode = findKthNode(temp, k);
            if (kthNode == NULL) break;

            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;

            ListNode* newHead = reverse(temp);

            if (prevNode == NULL) {
                head = newHead;
            } else {
                prevNode->next = newHead;
            }

            prevNode = temp;
            temp = nextNode;
        }        
        if (prevNode) prevNode->next = temp;
        return head;
    }
};

// Utility function to print the linked list
void printList(ListNode* head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Utility function to create linked list from array
ListNode* createList(int arr[], int n)
{
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; i++)
    {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Driver code
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int k = 2;
    int n = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = createList(arr, n);
    Solution sol;
    ListNode* newHead = sol.reverseKGroup(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(newHead);

    return 0;
}