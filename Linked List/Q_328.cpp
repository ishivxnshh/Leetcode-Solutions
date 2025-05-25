#include <iostream>
#include <vector>
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
    ListNode* oddEvenList(ListNode* head)
    {
        // Brute-Force Approach  (TC: O(2*n), SC: O(n))
        // if (head == NULL || head->next == NULL)
        // {
        //     return head;
        // }
        // vector<int> vec;
        // ListNode* temp = head;
        // while (temp != NULL && temp->next != NULL)
        // {
        //     vec.push_back(temp->val);
        //     temp = temp->next->next;
        // }
        // if (temp) vec.push_back(temp->val);
        // temp = head->next;
        // while (temp != NULL && temp->next != NULL)
        // {
        //     vec.push_back(temp->val);
        //     temp = temp->next->next;
        // }
        // if (temp) vec.push_back(temp->val);
        // int ind = 0;
        // temp = head;
        // while (temp != NULL)
        // {
        //     temp->val = vec[ind];
        //     temp = temp->next;
        //     ind++;
        // }
        // return head;

        // Optimal Approach  (TC: O(2*n/2 = n), SC: O(1))
        if(head == NULL || head -> next == NULL)
            return head;
        ListNode* odd = head;
        ListNode* even = head -> next;
        ListNode* evenHead = head -> next;
        while(even != NULL && even -> next != NULL)
        {
            odd -> next = odd -> next -> next;
            even -> next = even -> next -> next;
            odd = odd -> next;
            even = even -> next;
        }
        odd -> next = evenHead;
        return head;
    }
};

// Helper function to create a linked list from a vector
ListNode* createLinkedList(const vector<int>& vals)
{
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (size_t i = 1; i < vals.size(); ++i)
    {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print the linked list
void printLinkedList(ListNode* head)
{
    while (head)
    {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    vector<int> input = {1, 2, 3, 4, 5};
    ListNode* head = createLinkedList(input);

    Solution sol;
    ListNode* result = sol.oddEvenList(head);

    printLinkedList(result);

    return 0;
}