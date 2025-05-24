#include <iostream>
#include <map>
using namespace std;

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/* Solution Class */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // B-F Approach  (TC: O(n * 2*logn), SC: O(n))
        // map<ListNode*, int> mpp;
        // ListNode* temp = head;
        // while (temp != NULL)
        // {
        //     if (mpp.find(temp) != mpp.end())
        //         return true;
        //     mpp[temp] = 1;
        //     temp = temp->next;
        // }
        // return false;

        // Optimal Approach (Tortoise & Hare Approach) (TC: O(n), SC: O(1))
        //SelfWritten
        // ListNode* slow = head;
        // ListNode* fast = head;
        // int meet = 0;
        // while(fast != NULL && fast -> next != NULL)
        // {
        //     if(meet == 0)
        //     {
        //         slow = slow -> next;
        //         fast = fast -> next -> next;
        //         if(slow == fast)
        //         {
        //             slow = head;
        //             meet = 1;
        //         }
        //     }
        //     else
        //     {
        //         if(slow == fast)
        //             return slow; 
        //         slow = slow -> next;
        //         fast = fast -> next;  
        //     }
        // }
        // return NULL;  

        //OR
        ListNode* slow = head;
        ListNode* fast = head;
        int meet = 0;
        while(fast != NULL && fast -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast)
            {
                slow = head;
                while(slow != fast)
                {
                    slow = slow -> next;
                    fast = fast -> next;
                }
                return slow;
            }
        }
        return NULL;   
    }
};

/* Driver Code */
int main() {
    // Creating a cycle linked list: 1 -> 2 -> 3 -> 4 -> 2 (cycle)
    ListNode* node4 = new ListNode(4);
    ListNode* node3 = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node1 = new ListNode(1);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; // cycle here

    Solution sol;
    bool result = sol.hasCycle(node1);
    cout << "Cycle present? " << (result ? "Yes" : "No") << endl;

    // You can also test with an acyclic list by removing the cycle:
    node4->next = nullptr; // remove the cycle
    result = sol.hasCycle(node1);
    cout << "Cycle present after breaking? " << (result ? "Yes" : "No") << endl;

    return 0;
}
