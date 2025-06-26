#include <iostream>
#include <cmath>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    // int maxDepth(TreeNode *root)
    // {
    //     if (!root)
    //     {
    //         return 0;
    //     }
    //     return 1 + max(maxDepth(root->left), maxDepth(root->right));
    // }

    // bool isBalanced(TreeNode *root)
    // {
    //     if (root == NULL)
    //     {
    //         return true;
    //     }
    //     int lh = maxDepth(root->left);
    //     int rh = maxDepth(root->right);
    //     if (abs(lh - rh) > 1)
    //     {
    //         return false;
    //     }
    //     bool leftBalanced = isBalanced(root->left);
    //     bool rightBalanced = isBalanced(root->right);
    //     return leftBalanced && rightBalanced;
    // }

    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int lh = maxDepth(root -> left);
        int rh = maxDepth(root -> right);
        if (lh == -1 || rh == -1 || abs(lh - rh) > 1) return -1;        
        return 1 + max(lh, rh); 
    }

    bool isBalanced(TreeNode* root) {
        if (maxDepth(root) == -1) return false;
        else return true;
    }
};

// Driver Code
int main()
{
    // Creating test tree:
    //         1
    //        / \
    //       2   2
    //      /
    //     3
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);

    Solution sol;
    bool result = sol.isBalanced(root);

    if (result)
    {
        cout << "Tree is balanced." << endl;
    }
    else
    {
        cout << "Tree is not balanced." << endl;
    }

    return 0;
}
