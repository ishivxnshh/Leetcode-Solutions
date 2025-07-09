#include <iostream>
#include <vector>
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) return new TreeNode(val);
        TreeNode* curr = root;
        while (true)
        {
            if (curr->val > val)
            {
                if (curr->left == NULL)
                {
                    curr->left = new TreeNode(val);
                    break;
                }
                else curr = curr->left;
            }
            else
            {
                if (curr->right == NULL)
                {
                    curr->right = new TreeNode(val);
                    break;
                }
                else curr = curr->right;
            }
        }
        return root;
    }
};

// Helper function to print inorder traversal
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Main function (driver)
int main() {
    Solution sol;
    TreeNode* root = nullptr;

    vector<int> values = {10, 5, 15, 3, 7, 13, 18};
    for (int val : values) {
        root = sol.insertIntoBST(root, val);
    }

    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    return 0;
}