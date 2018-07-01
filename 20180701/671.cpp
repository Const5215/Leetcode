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
    int mn = INT_MAX, res = INT_MAX;
    void dfs(TreeNode* ths) {
        if (ths == NULL)
            return;
        if (ths->val < mn) {
            res = mn;
            mn = ths->val;
        }
        else if (ths->val != mn && ths->val < res){
            res = ths->val;
        }
        dfs(ths->left);
        dfs(ths->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        dfs(root);
        return res == INT_MAX? -1: res;
    }
};