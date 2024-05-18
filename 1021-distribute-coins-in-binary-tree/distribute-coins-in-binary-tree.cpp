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
    int func(TreeNode* root, int& ans) {
        if (!root)
            return 0;
        int l = func(root->left, ans);
        int r = func(root->right, ans);
        int extra = l + r + root->val - 1;
        ans += abs(extra);
        return extra;
    }
    
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        func(root, ans);
        return ans;
    }
};
