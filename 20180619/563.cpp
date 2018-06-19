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
    int dfs(TreeNode* root) {
        if (root == NULL) return 0;
        int a = dfs(root->left), b = dfs(root->right);
        res += abs(a-b);
        return a+b+root->val;
    }
    int findTilt(TreeNode* root) {
        dfs(root);
        return res;
    }
};