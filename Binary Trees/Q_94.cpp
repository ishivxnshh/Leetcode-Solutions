#include <iostream>
#include <vector>
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

class Solution
{
public:
    void iO(TreeNode *root, vector<int> &res)
    {
        if (!root)
            return;
        iO(root->left, res);
        res.push_back(root->val);
        iO(root->right, res);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        // vector<int> res;
        // iO(root, res);
        // return res;

        // iterative approach
        vector<int> inOrder;
        TreeNode *node = root;
        stack<TreeNode *> stk;
        while (true)
        {
            if (node)
            {
                stk.push(node);
                node = node->left;
            }
            else
            {
                if (stk.empty())
                    break;
                node = stk.top();
                stk.pop();
                inOrder.push_back(node->val);
                node = node->right;
            }
        }
        return inOrder;
    }
};

// ✅ Driver Code
int main()
{
    /*
        Tree structure:
              1
             / \
            2   3
           / \
          4   5

        Expected Inorder Traversal: 4 2 5 1 3
    */

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(4), new TreeNode(5));
    root->right = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int val : result)
    {
        cout << val << " ";
    }

    // Optional memory cleanup
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}