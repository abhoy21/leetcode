class Solution {
public:
    TreeNode* buildTreeHelper(vector<int>& preorder, int ps, int pe, unordered_map<int, int>& im, int is, int ie, vector<int>& inorder) {
        if (ps > pe || is > ie) return nullptr;
        TreeNode* root = new TreeNode(preorder[ps]);
        int idx = im[root->val];
        int numsLeft = idx - is;
        root->left = buildTreeHelper(preorder, ps + 1, ps + numsLeft, im, is, idx - 1, inorder);
        root->right = buildTreeHelper(preorder, ps + numsLeft + 1, pe, im, idx + 1, ie, inorder);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> im;
        for (int i = 0; i < inorder.size(); i++) {
            im[inorder[i]] = i;
        }
        return buildTreeHelper(preorder, 0, preorder.size() - 1, im, 0, inorder.size() - 1, inorder);
    }
};