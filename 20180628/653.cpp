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
    void dfs(vector<int>& tmp, TreeNode* now) {
        if (now == NULL)
            return;
        dfs(tmp, now->left);
        tmp.push_back(now->val);
        dfs(tmp, now->right);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> tmp;
        dfs(tmp, root);
        int i = 0, j = tmp.size()-1;
        while (i < j && tmp[i]+tmp[j] < k) i++;
        if (i < j && tmp[i]+tmp[j] == k)
            return true;
        while(i < j) {
            j--;
            while (i < j && tmp[i]+tmp[j] < k) i++;
            if (i < j && tmp[i]+tmp[j] == k)
                return true;
        }
        return false;
    }
};