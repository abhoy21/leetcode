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
    unordered_map<int, vector<int>> temp;
    int amountOfTime(TreeNode* root, int start) {
        dfs(root);
        queue<int> q;
        q.push(start);
        unordered_set<int> vis;
        int ans = -1;

        while(!q.empty()) {
            int size = q.size();
            ans++;
            for(int i = 0; i < size; i++){
                int e = q.front();
                q.pop();
                vis.insert(e);
                for(auto t: temp[e]) {
                    if(!vis.count(t))
                        q.push(t);
                }
            }
        }

        return ans;
    }
    void dfs(TreeNode* root) {
        if(!root)
            return;
        if(root->left) {
            temp[root->val].push_back(root->left->val);
            temp[root->left->val].push_back(root->val);
        } 
        if(root->right) {
            temp[root->val].push_back(root->right->val);
            temp[root->right->val].push_back(root->val);
        }

        dfs(root->left);
        dfs(root->right);
    }
};