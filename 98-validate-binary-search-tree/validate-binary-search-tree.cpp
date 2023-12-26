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
    bool f(TreeNode* root, long int min, long int max){
        if(root == nullptr)
            return true;
        if(root->val <= min || root->val >= max)
            return false;
        return f(root->left, min, root->val) && f(root->right, root->val, max);
    }
    bool isValidBST(TreeNode* root) {
        return f(root, LONG_MIN, LONG_MAX);
    }
};