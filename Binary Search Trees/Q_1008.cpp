#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// TreeNode definition
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
    int idx = 0;

    TreeNode* buildTree(vector<int> &preorder, int bound)
    {
        if (idx == preorder.size() || preorder[idx] > bound)
        {
            return NULL;
        }

        int val = preorder[idx++];
        TreeNode *root = new TreeNode(val);
        root->left = buildTree(preorder, val);
        root->right = buildTree(preorder, bound);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int> &preorder)
    {
        idx = 0;
        return buildTree(preorder, INT_MAX);
    }
};

// Inorder traversal to validate BST
void printInorder(TreeNode *root)
{
    if (!root)
    {
        return;
    }

    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main()
{
    Solution sol;

    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    TreeNode *root = sol.bstFromPreorder(preorder);

    cout << "Inorder traversal of constructed BST: ";
    printInorder(root);
    cout << endl;

    return 0;
}