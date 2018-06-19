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
    bool check(TreeNode* s, TreeNode* t) {
        if (s == NULL && t == NULL) return true;
        if (s == NULL || t == NULL) return false;
        if (s->val == t->val && check(s->left,t->left) && check(s->right, t->right))
            return true;
        return false;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL && t == NULL) return true;
        if (s == NULL || t == NULL) return false;
        if (s->val == t->val && check(s->left,t->left) && check(s->right, t->right))
            return true;
        if (s->left && isSubtree(s->left, t))
            return true;
        if (s->right && isSubtree(s->right,t))
            return true;
        return false;
    }
};