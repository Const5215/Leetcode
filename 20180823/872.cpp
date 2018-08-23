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
    vector<int> lst1,lst2;
    void vis(TreeNode* now, vector<int>& lst) {
        if (now == NULL)
            return;
        if (now->left == NULL && now->right == NULL) {
            lst.push_back(now->val);
            return;
        }
        vis(now->left, lst);vis(now->right, lst);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vis(root1, lst1);
        vis(root2, lst2);
        return lst1 == lst2;
    }
};