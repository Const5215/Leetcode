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
    map<TreeNode* ,TreeNode*> m;
    int mxdep = 0;
    queue<TreeNode*> q;
    void finddep(TreeNode* now, int nowdep) {
        if (now == NULL)
            return;
        if (now->left != NULL)
            m[now->left] = now;
        if (now->right != NULL)
            m[now->right] = now;
        if (nowdep > mxdep) {
            while(q.size()) q.pop();
            q.push(now);
            mxdep = nowdep;
        }
        else if (nowdep == mxdep)
            q.push(now);
        finddep(now->left, nowdep+1);
        finddep(now->right, nowdep+1);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        finddep(root, 1);
        set<TreeNode*> s;
        while(q.size() > 1) {
            queue<TreeNode*> nxt;
            while(q.size()) {
                TreeNode* now = q.front();q.pop();
                if (s.find(m[now]) == s.end()) {
                    nxt.push(m[now]);
                    s.insert(m[now]);
                }
            }
            q = nxt;
        }
        return q.front();
    }
};