class Solution {
public:
    long long last = -2147483649;
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        if (isValidBST(root->left) == false) return false;
        if (last >= (long long)root->val) return false;
        last = root->val;
        if (isValidBST(root->right) == false) return false;
        return true;
    }
};