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
    TreeNode* func(vector<int>& preorder, int& i, int ub){
        if(i == preorder.size() || preorder[i] > ub)
            return nullptr;
        TreeNode* node = new TreeNode(preorder[i++]);
        node->left = func(preorder, i, node->val);
        node->right = func(preorder, i, ub);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return func(preorder, i, INT_MAX);
    }
};