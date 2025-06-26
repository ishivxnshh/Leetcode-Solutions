#include <iostream>
#include <algorithm>
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
    // int maxi = 0;

    // int findHeight(TreeNode* node) {
    //     if (node == NULL) return 0;
    //     return 1 + max(findHeight(node -> left), findHeight(node -> right));
    // }

    // int diameterOfBinaryTree(TreeNode* root) {
    //     if(root == NULL) return 0;
    //     int lh = findHeight(root -> left);
    //     int rh = findHeight(root -> right);
    //     maxi = max(maxi, lh + rh);
    //     diameterOfBinaryTree(root -> left);
    //     diameterOfBinaryTree(root -> right);
    //     return maxi;
    // }

    int findHeight(TreeNode* node, int &maxi) {
        if (node == NULL) return 0;
        int lh = findHeight(node -> left, maxi);
        int rh = findHeight(node -> right, maxi);
        maxi = max(maxi, lh + rh);
        return 1 + max(lh, rh);        
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        findHeight(root, maxi);
        return maxi;
    }
};

// ------------------------
// ✅ Driver Code
// ------------------------

int main() {
    /*
           1
          / \
         2   3
        / \     
       4   5
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    int diameter = sol.diameterOfBinaryTree(root);
    cout << "Diameter of the binary tree is: " << diameter << endl;

    return 0;
}
