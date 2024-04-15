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
private:
    void dfs(TreeNode* root, int path, int& ans){
        if(!root)
            return;
        
        
        if(!root->left && !root->right){
            ans += path * 10 + root->val;
            return;
        }

        dfs(root->left, path * 10 + root->val, ans);
        dfs(root->right, path * 10 + root->val, ans); 
    }
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        
        dfs(root, 0, ans);        
        return ans;
    }
};