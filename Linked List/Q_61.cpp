#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution class
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // (tc: O(2n), sc:O(1))
        if(head == NULL || head -> next == NULL)
            return head;
        int len = 1;
        ListNode* tail = head;
        while(tail -> next != NULL)
        {
            len++;
            tail = tail -> next;
        } 
        if(k >= len)
            k = k % len;
        if(k == 0) return head;
        tail -> next = head;
        tail = head;
        int target = len - k;
        target--;
        while(target)
        {
            tail = tail -> next;
            target--;
        }        
        head = tail -> next;
        tail -> next = NULL;
        return head;
    }
};

// Helper function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < size; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Main function to test the code
int main() {
    Solution sol;
    int arr[] = {1, 2, 3, 4, 5};
    int k = 2;

    ListNode* head = createList(arr, 5);
    cout << "Original list: ";
    printList(head);

    head = sol.rotateRight(head, k);

    cout << "Rotated list: ";
    printList(head);

    return 0;
}