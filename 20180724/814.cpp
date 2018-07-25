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
    bool isprune(TreeNode* now) {
        if (now == NULL)
            return true;
        bool l = isprune(now->left), r = isprune(now->right);
        if (l)
            now->left = NULL;
        if (r)
            now->right = NULL;
        if (l && r && now->val == 0) {
            delete(now);
            return true;
        }
        else
            return false;
    }
    TreeNode* pruneTree(TreeNode* root) {
        return isprune(root)? NULL: root;
    }
};