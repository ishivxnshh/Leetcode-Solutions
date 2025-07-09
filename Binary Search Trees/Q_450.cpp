#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
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
    TreeNode* findMostRightOfLeftChild(TreeNode* root)
    {
        while (root->right != NULL)
        {
            root = root->right;
        }
        return root;
    }

    TreeNode* helper(TreeNode* root)
    {
        if (root->left == NULL)
            return root->right;
        else if (root->right == NULL)
            return root->left;
        else
        {
            TreeNode* rightChild = root->right;
            TreeNode* mostRightOfLeftChild = findMostRightOfLeftChild(root->left);
            mostRightOfLeftChild->right = rightChild;
            return root->left;
        }
    }

    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if (root == NULL)
            return root;

        if (root->val == key)
            return helper(root);

        TreeNode* temp = root;
        while (temp != NULL)
        {
            if (temp->val > key)
            {
                if (temp->left != NULL && temp->left->val == key)
                {
                    temp->left = helper(temp->left);
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->right != NULL && temp->right->val == key)
                {
                    temp->right = helper(temp->right);
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
        return root;
    }
};

// Utility function to insert a node into BST
TreeNode* insert(TreeNode* root, int val)
{
    if (root == NULL)
        return new TreeNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// Utility function to print level order traversal
void printLevelOrder(TreeNode* root)
{
    if (!root)
    {
        cout << "Tree is empty" << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode* curr = q.front();
        q.pop();
        cout << curr->val << " ";
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
    cout << endl;
}

// Driver code
int main()
{
    TreeNode* root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 6);
    insert(root, 2);
    insert(root, 4);
    insert(root, 7);

    cout << "Original Tree: ";
    printLevelOrder(root);

    int key = 3;
    Solution sol;
    root = sol.deleteNode(root, key);

    cout << "Tree After Deletion of " << key << ": ";
    printLevelOrder(root);

    return 0;
}