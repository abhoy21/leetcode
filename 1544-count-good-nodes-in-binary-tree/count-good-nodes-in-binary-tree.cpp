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
    void func(TreeNode* root, int &count, int curMax) {
        if(!root)
            return;
        if(root->val >= curMax) {
            count++;
            curMax = root->val;
        }

        func(root->left, count, curMax);
        func(root->right, count, curMax);
    }
    int goodNodes(TreeNode* root) {
        
        int count = 0;
        if(root)
            func(root, count, root->val);

        return count;
    }
};