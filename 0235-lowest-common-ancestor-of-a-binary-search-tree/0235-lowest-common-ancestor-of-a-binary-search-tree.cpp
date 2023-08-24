/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;
        
            if(p->val > curr->val && q->val > curr->val)
                curr = lowestCommonAncestor(curr->right, p, q);
            else if(p->val < curr->val && q->val < curr->val)
                curr = lowestCommonAncestor(curr->left, p, q);      
        return curr;
    }
};