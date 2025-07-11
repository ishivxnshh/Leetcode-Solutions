#include <iostream>
#include <stack>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator
{
private:
    stack<TreeNode *> stk;

    void pushAll(TreeNode *node)
    {
        while (node != NULL)
        {
            stk.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode *root)
    {
        pushAll(root);
    }

    int next()
    {
        TreeNode *temp = stk.top();
        stk.pop();
        pushAll(temp->right);
        return temp->val;
    }

    bool hasNext()
    {
        return !stk.empty();
    }
};

// ------------------------
// Driver Code with Test Case
// ------------------------
int main()
{
    // Construct the BST
    TreeNode *root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    // Create BSTIterator object
    BSTIterator *iterator = new BSTIterator(root);

    // Use iterator to print all elements in sorted order
    while (iterator->hasNext())
    {
        cout << iterator->next() << " ";
    }

    // Expected Output: 3 7 9 15 20

    return 0;
}