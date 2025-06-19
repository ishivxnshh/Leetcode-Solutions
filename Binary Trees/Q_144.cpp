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
    void pO(TreeNode *root, vector<int> &res)
    {
        if (!root)
            return;
        res.push_back(root->val);
        pO(root->left, res);
        pO(root->right, res);
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        // vector<int> res;
        // pO(root, res);
        // return res;

        // iterative approach
        if(!root) return {};
        vector<int> preOrder;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty())
        {
            TreeNode* node = stk.top();
            stk.pop();
            preOrder.push_back(node -> val);
            if(node -> right) stk.push(node -> right);
            if(node -> left) stk.push(node -> left);
        }
        return preOrder;
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
    */

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(4), new TreeNode(5));
    root->right = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.preorderTraversal(root);

    cout << "Preorder Traversal: ";
    for (int val : result)
    {
        cout << val << " ";
    }

    // Cleanup memory (optional for small code like this, but good habit)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}