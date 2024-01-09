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
    void func(TreeNode* root, vector<int> &v) {
        if(!root)
            return;
        if(!root->left && !root->right) {
            v.push_back(root->val);
            return;
        }
        func(root->left, v);
        func(root->right, v);

    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> r1, r2;
        func(root1, r1);
        func(root2, r2);

        return r1 == r2;
    }
};