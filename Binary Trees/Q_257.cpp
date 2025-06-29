#include <iostream>
#include <vector>
#include <string>
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
    void dfs(TreeNode* node, string path, vector<string>& res) {
        if (!node) return;

        if (!path.empty()) path += "->";
        path += to_string(node->val);

        if (!node->left && !node->right) {
            res.push_back(path);
            return;
        }

        dfs(node->left, path, res);
        dfs(node->right, path, res);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        dfs(root, "", res);
        return res;
    }
};

// ---------- DRIVER CODE ----------
int main() {
    /*
        Tree structure:
                1
               / \
              2   3
               \
                5

        Expected Output:
        1->2->5
        1->3
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    Solution sol;
    vector<string> paths = sol.binaryTreePaths(root);

    cout << "Root-to-Leaf Paths:" << endl;
    for (const string& path : paths) {
        cout << path << endl;
    }

    // Cleanup
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}