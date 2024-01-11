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
    int maxAncestorDiff(TreeNode* root) {
        return func(root, root->val, root->val);
    }

    int func(TreeNode* root, int mini, int maxi) {
        if(!root)
            return 0;
        mini = min(mini , root->val);
        maxi = max(maxi, root->val);
        int left = func(root->left, mini, maxi);
        int right = func(root->right, mini, maxi);
        return max(maxi - mini, max(left, right));
    }
};