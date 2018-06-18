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
    int res = 0;
    int fd(TreeNode* ths) {
        if (ths == NULL)
            return 0;
        if (ths->left == NULL && ths->right == NULL)
            return 1;
        int a = fd(ths->left), b = fd(ths->right);
        res = max(res,a+b);
        return max(a,b)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        fd(root);
        return res;
    }
};