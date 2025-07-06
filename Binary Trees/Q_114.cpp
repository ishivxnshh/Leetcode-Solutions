#include <iostream>
#include <stack>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* prev = NULL;

    void flatten(TreeNode* root) {
        /*
            Recursive Approach (reverse post order)
            Time Complexity: O(N), where N is the number of nodes in the tree.
            Space Complexity: O(N) due to recursion stack in the worst case (skewed tree).
        */
        if (root == NULL) return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;

        /*
            Iterative Approach
            Time Complexity: O(N), where N is the number of nodes in the tree.
            Space Complexity: O(N) in the worst case due to the stack (when the tree is completely unbalanced).
        */
        // if(root == NULL) return;
        // stack<TreeNode*> stk;
        // stk.push(root);
        // while(!stk.empty())
        // {
        //     TreeNode* cur = stk.top(); stk.pop();
        //     if(cur -> right) stk.push(cur -> right);
        //     if(cur -> left) stk.push(cur -> left);
        //     if(!stk.empty()) cur -> right = stk.top();
        //     cur -> left = NULL;
        // }
        
        /*
            Morris Traversal Based Approach
            Time Complexity: O(N), where N is the number of nodes in the tree.
            Space Complexity: O(1), since no extra space is used except for a few pointers.
        */
        if(root == NULL) return;
        TreeNode* curr = root;
        while(curr)
        {
            if (curr -> left != NULL)
            {
                TreeNode* prev = curr -> left;
                while(prev -> right)
                {
                    prev = prev -> right;
                }
                prev -> right = curr -> right;
                curr -> right = curr -> left;
                curr->left = nullptr;
            }
            curr = curr -> right;
        }
    }
};

// Helper function to print the right-skewed tree (like a linked list)
void printRightSkewed(TreeNode* root) {
    while (root) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}

// Driver code
int main() {
    /*
            1
           / \
          2   5
         / \   \
        3   4   6

        After flattening:
        1 - 2 - 3 - 4 - 5 - 6
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(3), new TreeNode(4));
    root->right = new TreeNode(5, nullptr, new TreeNode(6));

    Solution sol;
    sol.flatten(root);

    printRightSkewed(root);

    return 0;
}