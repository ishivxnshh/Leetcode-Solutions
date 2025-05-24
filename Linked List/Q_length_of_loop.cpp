/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int countCycleLength(ListNode* meetingPoint) {
        int length = 1;
        ListNode* temp = meetingPoint->next;
        while (temp != meetingPoint) {
            length++;
            temp = temp->next;
        }
        return length;
    }

    int lengthOfLoop(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Loop detected, count its length
                return countCycleLength(slow);
            }
        }

        // No loop found
        return 0;
    }
};