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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<TreeNode*>q;
        int x = 0;
        vector<int> v;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* root = q.front();
                q.pop();
                v.push_back(root->val);
                if(root->left != nullptr)
                    q.push(root->left);
                if(root->right != nullptr)
                    q.push(root->right);
            }
            if(x%2 == 0)
                ans.push_back(v);
            else{
                reverse(v.begin(), v.end());
                ans.push_back(v);
            }

            v.clear();
            x++;
        }

        return ans;
    }
};