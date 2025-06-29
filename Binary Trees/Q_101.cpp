#include <iostream>
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
    bool isSymetricHelp(TreeNode* left, TreeNode* right)
    {
        if (left == nullptr || right == nullptr) return left == right;
        if (left->val != right->val) return false;
        return isSymetricHelp(left->left, right->right) && isSymetricHelp(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        return root == nullptr || isSymetricHelp(root->left, root->right);
    }
};

// ---------- DRIVER CODE ----------
int main() {
    /*
        Constructing the following symmetric tree:
                1
               / \
              2   2
             / \ / \
            3  4 4  3

        Expected Output: Symmetric
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution sol;
    bool result = sol.isSymmetric(root);

    cout << (result ? "Symmetric" : "Not Symmetric") << endl;

    // Cleanup
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}