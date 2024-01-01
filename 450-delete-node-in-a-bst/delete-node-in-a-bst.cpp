/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* lastRightchild(TreeNode* root) {
        if (!root->right)
            return root;
        return lastRightchild(root->right);
    }

    TreeNode* helper(TreeNode* root) {
        if (!root->left)
            return root->right;
        else if (!root->right)
            return root->left;
        TreeNode* rightchild = root->right;
        TreeNode* lastRC = lastRightchild(root->left);
        lastRC->right = rightchild;
        return root->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return nullptr;
        if (root->val == key)
            return helper(root);
        TreeNode* node = root;
        TreeNode* parent = nullptr;

        // Find the node to be deleted and its parent
        while (root && root->val != key) {
            parent = root;
            if (root->val > key)
                root = root->left;
            else
                root = root->right;
        }

        if (!root)
            return node; // Node with key not found

        if (!parent) {
            // The node to be deleted is the root
            return helper(root);
        }

        // Update the parent's pointer to the deleted node
        if (parent->left == root)
            parent->left = helper(root);
        else
            parent->right = helper(root);

        return node;
    }
};
