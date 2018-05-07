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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if (n == 0) return res;
        return generate(1,n);
    }
private:
    vector<TreeNode*> generate(int L, int R) {
        vector<TreeNode*> res;
        TreeNode* ths = NULL;
        if (R < L) {
            res.push_back(ths);
            return res;
        }
        if (R == L) {
            ths = new TreeNode(R);
            res.push_back(ths);
            return res;
        }
        for (int i = L; i <= R; i++) {
            auto L_tree = generate(L, i-1);
            auto R_tree = generate(i+1,R);
            for (auto L_iter : L_tree)
                for (auto R_iter : R_tree) {
                    ths = new TreeNode(i);
                    ths->left = L_iter;
                    ths->right = R_iter;
                    res.push_back(ths);
                }
        }
        return res;
    }
};
