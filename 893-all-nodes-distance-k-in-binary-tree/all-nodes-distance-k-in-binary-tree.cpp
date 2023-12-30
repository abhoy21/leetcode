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
    void mark_parents(TreeNode* root, TreeNode* target, unordered_map<TreeNode*, TreeNode*>& parent_track) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                parent_track[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent_track[node->right] = node;
                q.push(node->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        mark_parents(root, target, parent_track);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int cur_level = 0;

        while (!q.empty()) {
            int size = q.size();
            if (cur_level == k) {
                vector<int> ans;
                while (!q.empty()) {
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return ans;
            }

            for (int i = 0; i < size; i++) {
                TreeNode* cur = q.front();
                q.pop();

                if (cur->left && !visited[cur->left]) {
                    q.push(cur->left);
                    visited[cur->left] = true;
                }
                if (cur->right && !visited[cur->right]) {
                    q.push(cur->right);
                    visited[cur->right] = true;
                }
                if (parent_track[cur] && !visited[parent_track[cur]]) {
                    q.push(parent_track[cur]);
                    visited[parent_track[cur]] = true;
                }
            }

            cur_level++;
        }

        // If we reach here, no nodes found at distance K
        return {};
    }
};