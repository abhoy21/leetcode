/**
 * Definition for a binary tree temp.
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
    int widthOfBinaryTree(TreeNode* root) {
        int width=INT_MIN;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            int size=q.size();
            int mmin=q.front().second;
            int first,last;
            for(int i=0;i<size;i++)
            {
                TreeNode* temp=q.front().first;
                long long int cur_id=q.front().second-mmin;
                q.pop();
                if(i==0)
                    first=cur_id;
                if(i==size-1)
                    last=cur_id;
                if(temp->left)
                    q.push({temp->left,2*cur_id+1});
                if(temp->right)
                    q.push({temp->right,2*cur_id+2});
            }
            width=max(width,last-first+1);
        }
        return width;
    }
};