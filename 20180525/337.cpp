class Solution {
public:
    int rob(TreeNode* root) {
        return find(root, 1);
    }
private:
    int find(TreeNode* ths, bool rob) {
        if (ths == NULL) return 0;
        if (rob)
            return max(find(ths->left, 0)+find(ths->right, 0)+ths->val, find(ths->left, 1)+find(ths->right, 1));
        else
            return find(ths->left, 1)+find(ths->right, 1);
    }
};