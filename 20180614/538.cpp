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
    int cur_sum = 0;
    void travel(TreeNode* root){
        if (!root) return;
        if (root->right)
            travel(root->right);
        root->val = (cur_sum += root->val);
        if (root->left) travel(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        travel(root);
        return root;
    }
};