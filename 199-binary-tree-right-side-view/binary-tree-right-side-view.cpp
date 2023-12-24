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
    void func(TreeNode* root, int level, vector<int>& right){
        if(root == nullptr)
            return;
        if(right.size() == level)
            right.push_back(root->val);
        func(root->right, level+1, right);
        func(root->left, level+1, right);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> right;
        func(root, 0, right);

        return right;
    }
};