class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) swap(p,q);
        if (root->val >= p->val && root->val <= q->val) return root;
        return root->val > p->val ? lowestCommonAncestor(root->left, p, q) : lowestCommonAncestor(root->right, p, q);
    }
};