class Solution {
public:
    int sumNumbers(TreeNode* root) {
        countw(root);
        return res;
    }
private:
    int countw(TreeNode* ths) {
        if (ths == NULL) return 0;
        int w = (countw(ths->left)+countw(ths->right))*10;
        if (w == 0) w=1;
        res += ths->val*w;
        return w;
    }
    int res = 0;
};