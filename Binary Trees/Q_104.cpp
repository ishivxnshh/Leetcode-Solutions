#include <iostream>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1 + max(lh, rh);
    }
};

// -------- Driver Code --------
int main() {
    /*
        Sample Tree:
                1
               / \
              2   3
             /
            4
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(4), nullptr);
    root->right = new TreeNode(3);

    Solution sol;
    int depth = sol.maxDepth(root);
    cout << "Maximum Depth of Binary Tree: " << depth << endl;

    // Clean up memory (optional here)
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}