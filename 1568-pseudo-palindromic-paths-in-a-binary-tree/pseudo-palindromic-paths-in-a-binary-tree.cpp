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
     void func(TreeNode* root, int& count, vector<int>& pseudo) {
        if (!root)
            return;

        pseudo[root->val]++;
        func(root->left, count, pseudo);
        func(root->right, count, pseudo);

        if (!root->left && !root->right) {
            int oddCount = 0;
            for (int i = 1; i < pseudo.size(); i++) {
                if (pseudo[i] % 2 != 0)
                    oddCount++;
            }
            if (oddCount <= 1)
                count++;
        }

        pseudo[root->val]--;
    }

    int pseudoPalindromicPaths(TreeNode* root) {
        int count = 0;
        vector<int> pseudo(10, 0);
        func(root, count, pseudo);
        return count;
    }
};