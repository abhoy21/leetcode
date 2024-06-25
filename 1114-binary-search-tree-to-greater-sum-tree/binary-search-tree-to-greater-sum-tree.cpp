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
    void func(TreeNode* root, int& sum){
        if(root){
            func(root->right, sum);
            sum += root->val;
            root->val = sum;
            func(root->left, sum);
        }
    }
    TreeNode* bstToGst(TreeNode* root) {
        int ans = 0;
        func(root, ans);

        return root;
    }
};