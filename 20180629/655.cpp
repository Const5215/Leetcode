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
    int finddep(TreeNode* now) {
        if (now == NULL)
            return 0;
        return max(finddep(now->left), finddep(now->right))+1;
    }
    void fill(vector<vector<string>>& res, TreeNode* ths, int L, int R, int dep) {
        if (ths == NULL)
            return;
        res[dep][(L+R)>>1] = to_string(ths->val);
        fill(res, ths->left, L, (L+R)>>1, dep+1);
        fill(res, ths->right, ((L+R)>>1)+1, R, dep+1);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int d = finddep(root);
        int l = 0;
        for (int i = 1; i <= d; i++)
            l = l*2+1;
        vector<vector<string>> res(d, vector<string>(l, ""));
        fill(res, root, 0, l, 0);
        return res;
    }
};