#include <iostream>
#include <queue>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;

        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);

        if (lh == rh) return (1 << lh) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int findLeftHeight(TreeNode* root) {
        int height = 0;
        while (root) {
            root = root->left;
            height++;
        }
        return height;
    }

    int findRightHeight(TreeNode* root) {
        int height = 0;
        while (root) {
            root = root->right;
            height++;
        }
        return height;
    }
};

// Helper function to create a binary tree from level order input
TreeNode* buildTree(vector<int> values) {
    if (values.empty() || values[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(values[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (i < values.size()) {
        TreeNode* current = q.front();
        q.pop();

        // Left child
        if (values[i] != -1) {
            current->left = new TreeNode(values[i]);
            q.push(current->left);
        }
        i++;
        if (i >= values.size()) break;

        // Right child
        if (values[i] != -1) {
            current->right = new TreeNode(values[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

int main() {
    Solution sol;

    // Example: Level order representation of complete binary tree
    vector<int> treeNodes = {1, 2, 3, 4, 5, 6};
    TreeNode* root = buildTree(treeNodes);

    int result = sol.countNodes(root);
    cout << "Total nodes: " << result << endl;

    return 0;
}