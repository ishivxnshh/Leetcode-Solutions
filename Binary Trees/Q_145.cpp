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
        pO(root->left, res);
        pO(root->right, res);
        res.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        // vector<int> res;
        // pO(root, res);
        // return res;

        // iterative approach using two stacks
        // if(!root) return {};
        // vector<int> postOrder;
        // stack<TreeNode*> stk1, stk2;
        // stk1.push(root);
        // while(!stk1.empty())
        // {
        //     TreeNode* node = stk1.top();
        //     stk1.pop();
        //     stk2.push(node);
        //     if(node -> left) stk1.push(node -> left);
        //     if(node -> right) stk1.push(node -> right);
        // }
        // while(!stk2.empty())
        // {
        //     postOrder.push_back(stk2.top() -> val);
        //     stk2.pop();
        // }
        // return postOrder;

        // iterative approach using one stack
        TreeNode* curr = root;
        stack<TreeNode*> stk;
        vector<int> postOrder;
        TreeNode* lastVisited = nullptr;

        while (curr != nullptr || !stk.empty())
        {
            if (curr)
            {
                stk.push(curr);
                curr = curr->left;
            }
            else
            {
                TreeNode* peek = stk.top();
                if (peek->right && lastVisited != peek->right)
                {
                    curr = peek->right;
                }
                else
                {
                    postOrder.push_back(peek->val);
                    lastVisited = peek;
                    stk.pop();
                }
            }
        }
        return postOrder;
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

        Expected Postorder Traversal: 4 5 2 3 1
    */

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(4), new TreeNode(5));
    root->right = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.postorderTraversal(root);

    cout << "Postorder Traversal: ";
    for (int val : result)
    {
        cout << val << " ";
    }

    // Clean up
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}