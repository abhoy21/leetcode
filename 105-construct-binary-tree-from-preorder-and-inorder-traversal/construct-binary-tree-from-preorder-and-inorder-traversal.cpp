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
    TreeNode* buildBTree(vector<int>& preorder, int prestart, int preend, vector<int>& inorder, int instart, int inend, unordered_map<int , int>& inmap) 
    {
        if(prestart > preend || instart > inend)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[prestart]);

        int inRoot = inmap[root->val];
        int numleft = inRoot - instart;

        root->left = buildBTree(preorder, prestart + 1, prestart + numleft, 
        inorder, instart, inRoot - 1, inmap);
        root->right = buildBTree(preorder, prestart + numleft + 1, preend, 
        inorder, inRoot + 1, inend, inmap);

        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int , int> inmap;
        for(int i = 0; i < inorder.size(); i++)
            inmap[inorder[i]] = i;

        TreeNode* root = buildBTree(preorder, 0, preorder.size()-1, 
        inorder, 0, inorder.size()-1, inmap);

        return root;
    }
};