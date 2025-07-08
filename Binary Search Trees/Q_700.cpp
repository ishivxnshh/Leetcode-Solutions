#include <iostream>
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
    TreeNode* searchBST(TreeNode* root, int val)
    {
        while (root != NULL && root->val != val)
        {
            root = root->val > val ? root->left : root->right;
        }
        return root;
    }
};

// Helper to insert nodes into the BST
TreeNode* insert(TreeNode* root, int val)
{
    if (root == NULL)
    {
        return new TreeNode(val);
    }

    if (val < root->val)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }

    return root;
}

// Driver code
int main()
{
    Solution obj;

    // Build the BST: [4,2,7,1,3]
    TreeNode* root = NULL;
    root = insert(root, 4);
    insert(root, 2);
    insert(root, 7);
    insert(root, 1);
    insert(root, 3);

    int searchVal = 2;
    TreeNode* result = obj.searchBST(root, searchVal);

    if (result != NULL)
    {
        cout << "Node found with value: " << result->val << endl;
    }
    else
    {
        cout << "Node not found." << endl;
    }

    return 0;
}