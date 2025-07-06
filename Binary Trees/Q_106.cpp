#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* buildTreeHelper(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, map<int, int>& mpp)
    {
        if (inStart > inEnd || postStart > postEnd) return nullptr;

        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);
        int inRoot = mpp[rootVal];
        int numsLeft = inRoot - inStart;

        root->left = buildTreeHelper(inorder, inStart, inRoot - 1, postorder, postStart, postStart + numsLeft - 1, mpp);
        root->right = buildTreeHelper(inorder, inRoot + 1, inEnd, postorder, postStart + numsLeft, postEnd - 1, mpp);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mpp;
        for (int i = 0; i < inorder.size(); ++i) {
            mpp[inorder[i]] = i;
        }

        return buildTreeHelper(inorder, 0, inorder.size() - 1,
                               postorder, 0, postorder.size() - 1, mpp);
    }
};

// Helper function to print inorder traversal of the tree
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    Solution sol;
    TreeNode* root = sol.buildTree(inorder, postorder);

    cout << "Inorder traversal of the constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}