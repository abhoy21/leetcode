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
    int cc = 0;
    string cameraCount(TreeNode* root){
        if(root == nullptr)
            return "ok";
        string left = cameraCount(root->left);
        string right = cameraCount(root->right);

        if(left == "want" || right == "want"){
            cc++;
            return "provide";
        }
        else if(left == "provide" || right == "provide")
            return "ok";
        else
            return "want";
    }
    int minCameraCover(TreeNode* root) {
        if(cameraCount(root) == "want")
            cc++;


        return cc;
    }
};