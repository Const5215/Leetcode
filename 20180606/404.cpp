class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) return 0;
        return (root->left && root->left->left == NULL && root->left->right == NULL ? root->left->val : 0)+sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
    }
};