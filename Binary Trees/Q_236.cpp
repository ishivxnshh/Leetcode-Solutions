#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Brute-Force Approach: finding the paths from root to both p and q respectively, and then fine last common node between both the node arrays
        // Optimal Approach! (tc: O(n), sc: O(n))
        // Base case: if root is null or equals one of the nodes
        if (root == NULL || root == p || root == q) return root;

        // Recurse on left and right subtrees
        TreeNode* lN = lowestCommonAncestor(root->left, p, q);
        TreeNode* rN = lowestCommonAncestor(root->right, p, q);

        // If one node is found on each side, current root is LCA
        if (lN && rN) return root;

        // Otherwise return the non-null node
        return lN ? lN : rN;
    }
};

// ---------- DRIVER CODE ----------
int main() {
    /*
        Constructing the following binary tree:
                3
               / \
              5   1
             / \ / \
            6  2 0  8
              / \
             7   4

        LCA(5, 1) = 3
        LCA(6, 4) = 5
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;

    TreeNode* p1 = root->left;             // 5
    TreeNode* q1 = root->right;            // 1
    TreeNode* lca1 = sol.lowestCommonAncestor(root, p1, q1);
    cout << "LCA of 5 and 1: " << lca1->val << endl;

    TreeNode* p2 = root->left->left;       // 6
    TreeNode* q2 = root->left->right->right; // 4
    TreeNode* lca2 = sol.lowestCommonAncestor(root, p2, q2);
    cout << "LCA of 6 and 4: " << lca2->val << endl;

    // Cleanup (optional for small code)
    delete root->left->right->left;
    delete root->left->right->right;
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
