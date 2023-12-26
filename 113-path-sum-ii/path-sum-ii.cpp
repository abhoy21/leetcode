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
    void func(TreeNode* root, int targetSum, vector<int>& temp, vector<vector<int>>& ans){
        temp.push_back(root->val);
        targetSum -= root->val;

        if(root->left == nullptr && root->right == nullptr){
            if(targetSum == 0)
                ans.push_back(temp);

        }

        if(root->left)
            func(root->left, targetSum, temp, ans);
        if(root->right)
            func(root->right, targetSum, temp, ans);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root == nullptr)
            return ans;
        vector<int> temp;
        func(root, targetSum, temp, ans);

        return ans;
    }
};