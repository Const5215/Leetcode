class Solution {
    public:
    int res = INT_MAX, pst = INT_MAX;
    void find(TreeNode* root) {
        if (root == NULL)
            return;
        find(root->left);
        if (res != INT_MAX || pst != INT_MAX)
            res = min(root->val-pst, res);
        pst = root->val;
        find(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        find(root);
        return res;
    }
};