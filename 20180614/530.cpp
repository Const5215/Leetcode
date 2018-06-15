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
    int v = -1, res = INT_MAX;
    void find(TreeNode* ths) {
        if (ths == NULL) return;
        find(ths->left);
        if (v >= 0)
            res = min(res, ths->val-v);
        v = ths->val;
        find(ths->right);
    }
    int getMinimumDifference(TreeNode* root) {
        find(root);
        return res;
    }
};