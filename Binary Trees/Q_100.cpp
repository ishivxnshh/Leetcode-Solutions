#include <iostream>
#include <queue>
#include <vector>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr)
            return p == q;
        return (p->val == q->val) &&
               isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};

/* Utility: Build tree from level order input */
TreeNode* buildTreeFromLevelOrder(const vector<string>& nodes) {
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
    // Sample Input:
    // Tree 1: [1,2,3]
    // Tree 2: [1,2,3]
    vector<string> tree1 = {"1", "2", "3"};
    vector<string> tree2 = {"1", "2", "3"};

    TreeNode* root1 = buildTreeFromLevelOrder(tree1);
    TreeNode* root2 = buildTreeFromLevelOrder(tree2);

    Solution sol;
    bool same = sol.isSameTree(root1, root2);

    cout << (same ? "Trees are the same." : "Trees are different.") << endl;

    return 0;
}