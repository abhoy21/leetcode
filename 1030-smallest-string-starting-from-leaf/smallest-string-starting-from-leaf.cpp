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
    string ans = "";
    string smallestFromLeaf(TreeNode* root) {
        string path = "";
        dfs(root, path);

        return ans;
    }

    void dfs(TreeNode* root, string& path){
        if(!root) return;

        path += root->val + 'a';
   
        if(!root->left && !root->right){
            string temp = path;
            reverse(temp.begin(), temp.end());

            if(ans == "" || temp < ans)
                ans = temp;
        }

        dfs(root->left, path);
        dfs(root->right, path);
        path.pop_back();
    }
};