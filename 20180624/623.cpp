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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (root == NULL)
            return NULL;
        if (d == 1) {
            TreeNode *ths = new TreeNode(v);
            ths->left = root;
            return ths;
        }
        if (d == 2) {
            TreeNode *lsub = new TreeNode(v), *rsub = new TreeNode(v);
            lsub->left = root->left;
            rsub->right = root->right;
            root->left = lsub;
            root->right = rsub;
            return root;
        }
        root->left = addOneRow(root->left, v, d-1);
        root->right = addOneRow(root->right, v, d-1);
        return root;
    }
};