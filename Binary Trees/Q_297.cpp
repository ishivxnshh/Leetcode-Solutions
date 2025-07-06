#include <iostream>
#include <sstream>
#include <queue>
#include <string>
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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        queue<TreeNode*> q;
        q.push(root);
        string serializedString = "";
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (!node) {
                serializedString.append("#,");
            } else {
                serializedString.append(to_string(node->val) + ',');
                q.push(node->left);
                q.push(node->right);
            }
        }
        return serializedString;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();

            getline(s, str, ',');
            if (str == "#") node->left = NULL;
            else {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }

            getline(s, str, ',');
            if (str == "#") node->right = NULL;
            else {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }
        return root;
    }
};

// Helper function for inorder traversal to verify correctness
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Driver code
int main() {
    // Manually creating a binary tree:
    //       10
    //      /  \
    //     20   30
    //         /  \
    //        40  50
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->right->left = new TreeNode(40);
    root->right->right = new TreeNode(50);

    Codec ser, deser;
    
    // Serialize
    string serialized = ser.serialize(root);
    cout << "Serialized: " << serialized << endl;

    // Deserialize
    TreeNode* deserializedRoot = deser.deserialize(serialized);

    // Inorder traversal of the deserialized tree
    cout << "Inorder of deserialized tree: ";
    inorder(deserializedRoot);
    cout << endl;

    return 0;
}
