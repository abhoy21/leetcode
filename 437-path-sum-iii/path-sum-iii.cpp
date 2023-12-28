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
    void help(TreeNode *root,vector<int> v,int ts,int &ans){
        if(!root){
            return ;
        }
        v.push_back(root->val);
        help(root->left,v,ts,ans);
        help(root->right,v,ts,ans);
        long long int f=0;
        for (int i = v.size()-1; i>=0; i--)
        {
            f+=v[i];
            if(f==ts){
                ans++;
            }
 
        }
        v.pop_back();
        
    }
    int pathSum(TreeNode* root, int ts) {
        int ans=0;
        vector<int> v;
        help(root,v,ts,ans);
        return ans;
    }
};