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
    int minDepth(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        if (root == NULL) return 0;
        q.push(make_pair(root,1));
        while(q.size()) {
            if (q.front().first->left == NULL && q.front().first->right == NULL) return q.front().second;
            if (q.front().first->left)
                q.push(make_pair(q.front().first->left,q.front().second+1));
            if (q.front().first->right)
                q.push(make_pair(q.front().first->right,q.front().second+1));
            q.pop();
        }
    }
};
