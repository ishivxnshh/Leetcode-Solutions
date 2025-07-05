#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &childParent)
    {
        if (root == NULL) return;
        if(root->left)
        {
            childParent[root->left] = root;
            markParent(root->left, childParent);
        }
        if(root->right)
        {
            childParent[root->right] = root;
            markParent(root->right, childParent);
        }  
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        /*
        Time Complexity: O(N), where N is the number of nodes in the tree.
            - markParent traverses all nodes once: O(N)
            - BFS visits each node at most once: O(N)
        Space Complexity: O(N)
            - childParent and visited maps store up to N nodes: O(N)
            - queue can hold up to N nodes in the worst case: O(N)
        */

        unordered_map<TreeNode*, TreeNode*> childParent;
        markParent(root, childParent);
        
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int currentLevel = 0;
        while (!q.empty())
        {
            if (currentLevel == k) break;
            currentLevel++;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode* current = q.front(); q.pop();
                if (current->left && !visited[current->left])
                {
                    q.push(current->left);
                    visited[current->left] = true;
                }
                if (current->right && !visited[current->right])
                {
                    q.push(current->right);
                    visited[current->right] = true;
                }
                if (childParent[current] && !visited[childParent[current]])
                {
                    q.push(childParent[current]);
                    visited[childParent[current]] = true;
                }
            }
        }
        vector<int> res;
        while (!q.empty())
        {
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};

// Helper to build a simple tree for testing
TreeNode* buildSampleTree(TreeNode*& targetRef) {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // Set target to node with value 5
    targetRef = root->left;
    return root;
}

int main() {
    Solution sol;
    TreeNode* target = nullptr;
    TreeNode* root = buildSampleTree(target);

    int k = 2;
    vector<int> result = sol.distanceK(root, target, k);

    cout << "Nodes at distance " << k << " from target: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}