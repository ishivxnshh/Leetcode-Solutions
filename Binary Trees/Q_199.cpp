#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    // vector<int> rightSideView(TreeNode* root) {
    //     if (root == NULL) return {};
    //     queue<pair<TreeNode*, int>> q;
    //     map<int, TreeNode*> mpp;
    //     vector<int> vec;
    //     q.push({root, 0});
    //     while (!q.empty())
    //     {
    //         auto p = q.front();
    //         q.pop();
    //         TreeNode* node = p.first;
    //         int level = p.second;
    //         mpp[level] = node; // stores last node at each level (left to right)
    //         if (node->left) q.push({node->left, level + 1});
    //         if (node->right) q.push({node->right, level + 1});
    //     }
    //     for (auto it : mpp)
    //     {
    //         vec.push_back(it.second->val);
    //     }
    //     return vec;
    // }

    void preOrder(TreeNode* root, int level, vector<int> &res) { // root right left
        if (root == NULL) return;
        if (level == res.size()) res.push_back(root -> val);
        preOrder(root -> right, level + 1, res);
        preOrder(root -> left, level + 1, res);
    }

    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL) return {};
        vector<int> res;
        preOrder(root, 0, res);
        return res;
    }
};

// ---------- DRIVER CODE BELOW ----------
int main() {
    /*
        Tree structure:
                1
               / \
              2   3
               \   \
                5   4
        Expected right side view: 1 3 4
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution sol;
    vector<int> result = sol.rightSideView(root);

    cout << "Right Side View: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Cleanup (optional but good practice)
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}