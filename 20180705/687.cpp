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
    int res = 0;
    int getpath(TreeNode* root) {
        if (root == NULL)
            return 0;
        int l = getpath(root->left);
        int r = getpath(root->right);
        int ths = 0, mx = 0;
        if (root->left && root->left->val == root->val) {
            ths += l;
            mx = max(mx, l);
        }
        if (root->right && root->right->val == root->val) {
            ths += r;
            mx = max(mx, r);
        }
        res = max(res, ths);
        return mx+1;
    }
    int longestUnivaluePath(TreeNode* root) {
        getpath(root);
        return res;
    }
};