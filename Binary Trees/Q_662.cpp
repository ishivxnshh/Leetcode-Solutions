#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

/** Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int ans = 0;

        while (!q.empty()) {
            int s = q.size();
            int minIndex = q.front().second;
            int first = 0, last = 0;

            for (int i = 0; i < s; i++) {
                auto p = q.front(); q.pop();
                TreeNode* node = p.first;
                int ind = p.second - minIndex;

                if (i == 0) first = ind;
                if (i == s - 1) last = ind;

                if (node->left)
                    q.push({node->left, 2 * ind + 1});
                if (node->right)
                    q.push({node->right, 2 * ind + 2});
            }

            ans = max(ans, last - first + 1);
        }

        return ans;
    }
};

// 🔽 Driver code to test the function
int main() {
    /*
         Example Tree:
               1
              / \
             3   2
            /     \
           5       9
          /         \
         6           7

        Width at the bottom level is 8 (from 6 to 7)
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->right->right = new TreeNode(9);
    root->left->left->left = new TreeNode(6);
    root->right->right->right = new TreeNode(7);

    Solution sol;
    int result = sol.widthOfBinaryTree(root);
    cout << "Maximum width of binary tree: " << result << endl;

    // Clean up memory (not required in competitive coding but good practice)
    delete root->left->left->left;
    delete root->left->left;
    delete root->left;
    delete root->right->right->right;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}