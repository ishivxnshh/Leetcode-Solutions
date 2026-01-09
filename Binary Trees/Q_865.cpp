#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
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
    class Pair {
        public:
            TreeNode* node;
            int dist;
            Pair (TreeNode* node, int dist) {
                this -> node = node;
                this -> dist = dist;
            }
    };

    int height(TreeNode* root) {
        if (root == NULL) return 0;
        int l = height(root -> left);
        int r = height(root -> right);
        return max(l, r) + 1;
    }

    Pair solve (TreeNode* root, int d) {
        if (root == NULL) return Pair (NULL, d);
        Pair l = solve(root -> left, d + 1);
        Pair r = solve(root -> right, d + 1);
        if (l.dist == r.dist) return Pair(root, l.dist);
        return (l.dist > r.dist) ? l : r;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        // (tc: O(n), sc: O(n))
        // int l = height(root -> left);
        // int r = height(root -> right);
        // if (l == r) return root;
        // TreeNode* node;
        // if (l > r) node = subtreeWithAllDeepest(root -> left);
        // else node = subtreeWithAllDeepest(root -> right);
        // return node;

        // better approach (tc: O(n), sc: O(h))
        Pair p = solve(root, 0);
        return p.node;
    }
};

/* ---------------- DRIVER CODE ---------------- */

int main() {
    /*
            3
           / \
          5   1
         / \   \
        6   2   8
           / \
          7   4
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution obj;
    TreeNode* ans = obj.subtreeWithAllDeepest(root);

    if (ans)
        cout << ans->val << endl;
    else
        cout << "NULL" << endl;

    return 0;
}
