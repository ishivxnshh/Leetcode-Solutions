#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// Solution class
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        // Brute-Force Approach (tc: O(2n), sc: O(n + n) = O(2n))
        // Node *temp = head;
        // unordered_map<Node *, Node *> mpp;
        // while (temp != NULL)
        // {
        //     Node *newNode = new Node(temp->val);
        //     mpp[temp] = newNode;
        //     temp = temp->next;
        // }
        // temp = head;
        // while (temp != NULL)
        // {
        //     Node *copyNode = mpp[temp];
        //     copyNode->next = mpp[temp->next];
        //     copyNode->random = mpp[temp->random];
        //     temp = temp->next;
        // }
        // return mpp[head];

        // Optimal Approach (tc: O(3n), sc: O(n))
        Node* temp = head;
        while(temp != NULL)
        {
            Node* front = temp -> next;
            temp -> next = new Node(temp -> val);
            temp = temp -> next;
            temp -> next = front;
            temp = temp -> next;
        }
        temp = head;
        while(temp != NULL)
        {
            if(temp -> random) temp -> next -> random = temp -> random -> next;
            temp = temp -> next -> next;
        }
        Node* dummyNode = new Node(-1);
        Node* mover = dummyNode;
        temp = head;
        while(temp != NULL)
        {
            mover -> next = temp -> next;
            mover = mover -> next;
            temp -> next = temp -> next -> next;
            temp = temp -> next;
        }
        return dummyNode -> next;
    }
};

// Helper function to print the list
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << "Val: " << temp->val << ", Random: ";
        if (temp->random)
        {
            cout << temp->random->val;
        }
        else
        {
            cout << "NULL";
        }
        cout << endl;
        temp = temp->next;
    }
}

// Sample Test Case
int main()
{
    // Creating nodes
    Node *n1 = new Node(7);
    Node *n2 = new Node(13);
    Node *n3 = new Node(11);
    Node *n4 = new Node(10);
    Node *n5 = new Node(1);

    // Setting up next pointers
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    // Setting up random pointers
    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;

    Solution sol;
    Node *copiedList = sol.copyRandomList(n1);

    cout << "Original List:" << endl;
    printList(n1);

    cout << "\nCopied List:" << endl;
    printList(copiedList);

    return 0;
}
