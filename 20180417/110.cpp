class Solution {
public:
    int find(TreeNode* ths) {
        if (ths == NULL) return 0;
        int L = find(ths->left);
        if (L == -1) return -1;
        int R = find(ths->right);
        if (R == -1) return -1;
        return abs(L-R) <= 1 ? max(L,R)+1 : -1;
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true; 
        int L = find(root->left);
        if (L == -1) return false;
        int R = find(root->right);
        if (R == -1) return false;
        return abs(L-R) <= 1;
    }
};