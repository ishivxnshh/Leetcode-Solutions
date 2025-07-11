#include <iostream>
#include <stack>
using namespace std;

/* Tree Node Definition */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/* BSTIterator Class */
class BSTIterator {
private:
    stack<TreeNode*> stk;
    bool reverse;

    void pushAll(TreeNode* node) {
        while (node != NULL) {
            stk.push(node);
            if (reverse) node = node->right;
            else node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    int next() {
        TreeNode* temp = stk.top();
        stk.pop();
        if (!reverse) pushAll(temp->right);
        else pushAll(temp->left);
        return temp->val;
    }

    bool hasNext() {
        return !stk.empty();
    }
};

/* Solution Class */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        BSTIterator l(root, false);  // Inorder
        BSTIterator r(root, true);   // Reverse Inorder

        int i = l.next();
        int j = r.next();

        while (i < j) {
            if (i + j == k) return true;
            else if (i + j < k) i = l.next();
            else j = r.next();
        }

        return false;
    }
};

/* ----------- DRIVER CODE ----------- */
int main() {
    // Construct the BST manually:
    //         5
    //       /   \
    //      3     6
    //     / \     \
    //    2   4     7

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    Solution sol;
    int k = 9;

    if (sol.findTarget(root, k))
        cout << "Found a pair that sums to " << k << endl;
    else
        cout << "No pair found with sum " << k << endl;

    return 0;
}