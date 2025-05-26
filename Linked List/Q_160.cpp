#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *collisionPoint(ListNode *t1, ListNode *t2, int d)
    {
        while(d)
        {
            d--;
            t2 = t2 -> next;
        }        
        while(t1 != t2)
        {
            t1 = t1 -> next;
            t2 = t2 -> next;
        }
        return t1;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Brute-Force Approach (tc: O(m + n), sc: O(m))
        // unordered_map<ListNode*, int> mpp;
        // ListNode* temp = headA;
        // while (temp != NULL) {
        //     mpp[temp] = 1;
        //     temp = temp->next;
        // }
        // temp = headB;
        // while (temp != NULL) {
        //     if (mpp.find(temp) != mpp.end())
        //         return temp;
        //     temp = temp->next;
        // }
        // return temp;

        // Better Approach (tc: O(m + n + max(m, n)), sc: O(1))
        // int cntA = 0;
        // ListNode* temp = headA;
        // while(temp != NULL)
        // {
        //     cntA++;
        //     temp = temp -> next;
        // }
        // int cntB = 0;
        // temp = headB;
        // while(temp != NULL)
        // {
        //     cntB++;
        //     temp = temp -> next;
        // }
        // if (cntA < cntB)
        //     return collisionPoint(headA, headB, cntB - cntA);
        // else
        //     return collisionPoint(headB, headA, cntA - cntB);

        // Optimal Approach (tc: O(m + n), sc: O(1))
        if(headA == NULL || headB == NULL)  return NULL;
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        while(t1 != t2)
        {
            t1 = t1 -> next;
            t2 = t2 -> next;
            if(t1 == t2) return t1;
            if(t1 == NULL) t1 = headB;
            if(t2 == NULL) t2 = headA;
        }
        return t1;
    }
};

// Helper function to print list from a given node
void printList(ListNode* node) {
    while (node != NULL) {
        cout << node->val << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

// Test case
int main() {
    // Common nodes
    ListNode* intersect = new ListNode(8);
    intersect->next = new ListNode(10);

    // List A: 3 -> 7 -> 8 -> 10
    ListNode* headA = new ListNode(3);
    headA->next = new ListNode(7);
    headA->next->next = intersect;

    // List B: 99 -> 1 -> 8 -> 10
    ListNode* headB = new ListNode(99);
    headB->next = new ListNode(1);
    headB->next->next = intersect;

    Solution solution;
    ListNode* result = solution.getIntersectionNode(headA, headB);

    if (result != NULL)
        cout << "Intersection at node with value: " << result->val << endl;
    else
        cout << "No intersection found." << endl;

    return 0;
}