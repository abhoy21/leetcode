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
        if(!root->right)
            return root;
        return lastRightchild(root->right);
    }
    TreeNode* helper(TreeNode* root){
        if(!root->left)
            return root->right;
        else if(!root->right)
            return root->left;
        TreeNode* rightchild = root->right;
        TreeNode* lastRC = lastRightchild(root->left);
        lastRC->right = rightchild;

        return root->left;

    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return nullptr;
        if(root->val == key)
            return helper(root);
        TreeNode* node = root;
        while(root) {
            if(root->val > key){
                if(root->left && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                }
                else
                    root = root->left;
            }
            else{
                if(root->right && root->right->val == key){
                    root->right = helper(root->right);
                    break;
                }
                else
                    root= root->right;
            }
        }

        return node;
    }
};
