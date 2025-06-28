#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        bool leftToRight = true;
        while(!nodesQueue.empty())
        {
            int size = nodesQueue.size();
            vector<int> row(size);
            for (int i = 0; i < size; i++)
            {
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();
                int index = (leftToRight) ? i : (size - 1 - i);
                row[index] = node->val;
                if (node->left) nodesQueue.push(node->left);
                if (node->right) nodesQueue.push(node->right);
            }
            leftToRight = !leftToRight;
            res.push_back(row);
        }
        return res;
    }
};

// Helper function to print the 2D vector
void printZigzagTraversal(const vector<vector<int>>& result) {
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
}

// Driver code
int main() {
    /*
       Construct the following binary tree:
               1
              / \
             2   3
            / \   \
           4   5   6
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution solution;
    vector<vector<int>> result = solution.zigzagLevelOrder(root);

    cout << "Zigzag Level Order Traversal:" << endl;
    printZigzagTraversal(result);

    // Free allocated memory (optional in small test code, but good practice)
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}