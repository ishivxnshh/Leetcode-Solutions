class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Only Approach (tc: O(max(m, n)), sc: O(max(m, n)))
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* current = dummyNode;
        int carry = 0;
        while(t1 != NULL || t2 != NULL)
        {
            int sum = carry;
            if(t1) sum += t1->val;
            if(t2) sum += t2->val;

            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;

            current->next = newNode;
            current = current->next;

            if(t1) t1 = t1->next;
            if(t2) t2 = t2->next;
        }
        if(carry)
        {
            current->next = new ListNode(carry);
        }
        return dummyNode->next;
    }
};
