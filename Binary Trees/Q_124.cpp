#include <iostream>
#include <climits>
#include <queue>
using namespace std;

/* Definition for a binary tree node */
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
    int maxPathDown(TreeNode* root, int &maxi)
    {
        if (root == nullptr) return 0;
        int lsum = max(0, maxPathDown(root->left, maxi));
        int rsum = max(0, maxPathDown(root->right, maxi));
        maxi = max(maxi, lsum + rsum + root->val);
        return root->val + max(lsum, rsum);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPathDown(root, maxi);
        return maxi;
    }
};

/* ----------- Driver Code Below ----------- */

TreeNode* buildTreeFromLevelOrder(vector<string> nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != "null") {
            current->left = new TreeNode(stoi(nodes[i]));
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "null") {
            current->right = new TreeNode(stoi(nodes[i]));
            q.push(current->right);
        }
        i++;
    }
    return root;
}

int main() {
    // Sample Input: [-10, 9, 20, null, null, 15, 7]
    vector<string> nodes = {"-10", "9", "20", "null", "null", "15", "7"};
    TreeNode* root = buildTreeFromLevelOrder(nodes);

    Solution sol;
    int result = sol.maxPathSum(root);

    cout << "Maximum Path Sum: " << result << endl; // Expected Output: 42

    return 0;
}