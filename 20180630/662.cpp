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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0,0}});
        int mn = 0, now = 0, res = 0;
        while(q.size()) {
            auto ths = q.front();
            q.pop();
            if (ths.first == NULL)
                continue;
            if (ths.second.first != now) {
                now++;
                mn = ths.second.second;
                res = max(res, 1);
            }
            else {
                res = max(res, ths.second.second-mn+1);
            }
            q.push({ths.first->left, {ths.second.first+1, ths.second.second*2}});
            q.push({ths.first->right, {ths.second.first+1, ths.second.second*2+1}});
        }
        return res;
    }
};