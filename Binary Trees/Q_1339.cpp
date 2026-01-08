#include <bits/stdc++.h>
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
    long long SUM = 0;
    long long maxP = 0;

    int totalSum(TreeNode* root)
    {
        if (!root) return 0;

        int left = totalSum(root->left);
        int right = totalSum(root->right);

        return root->val + left + right;
    }

    long long find(TreeNode* root)
    {
        if (!root) return 0;

        long long left = find(root->left);
        long long right = find(root->right);

        long long subTreeSum = root->val + left + right;
        long long remaining = SUM - subTreeSum;

        maxP = max(maxP, subTreeSum * remaining);

        return subTreeSum;
    }

    int maxProduct(TreeNode* root)
    {
        if (!root) return 0;

        SUM = totalSum(root);
        find(root);

        return maxP % 1000000007;
    }
};

/* ---------------- DRIVER CODE ---------------- */

int main()
{
    /*
        Example Tree:
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
    cout << sol.maxProduct(root) << endl;

    return 0;
}
