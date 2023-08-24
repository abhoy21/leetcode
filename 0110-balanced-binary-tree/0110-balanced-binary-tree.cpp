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
    int bst(TreeNode* root, int& height)
    {
        if(root == nullptr) return 0;

        int l = bst(root->left, height) + 1;
        int r = bst(root->right, height) + 1;

        if(abs(r-l) > 1) height = 0;

        return max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int height = 1;

        bst(root, height);

        if(height != 0) return true;

        return false;
    }
};