#include <iostream>
#include <climits>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    bool isValidBST(TreeNode *root, long long minR, long long maxR)
    {
        if (root == NULL)
        {
            return true;
        }

        if (root->val <= minR || root->val >= maxR)
        {
            return false;
        }

        return isValidBST(root->left, minR, root->val) &&
               isValidBST(root->right, root->val, maxR);
    }

    bool isValidBST(TreeNode *root)
    {
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }
};

// -------------------- DRIVER CODE --------------------
int main()
{
    /*
        Sample BST:
                5
               / \
              3   7
             / \   \
            2   4   8
    */

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(8);

    Solution sol;
    if (sol.isValidBST(root))
    {
        cout << "The tree is a valid BST." << endl;
    }
    else
    {
        cout << "The tree is NOT a valid BST." << endl;
    }

    return 0;
}