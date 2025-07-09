#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    int count = 0;
    int result = -1;

    void inorder(TreeNode *root, int k)
    {
        if (!root || count >= k)
        {
            return;
        }

        inorder(root->left, k);

        count++;
        if (count == k)
        {
            result = root->val;
            return;
        }

        inorder(root->right, k);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        inorder(root, k);
        return result;
    }
};

// Driver code
int main()
{
    /*
        Construct the following BST:
                5
               / \
              3   6
             / \
            2   4
           /
          1
    */

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    int k = 3;

    Solution obj;
    int ans = obj.kthSmallest(root, k);

    cout << "The " << k << "rd smallest element is: " << ans << endl;

    return 0;
}