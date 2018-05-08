class Solution {
private:
    void dfs(TreeNode* now, vector<TreeNode*>& lst) {
        if (now == NULL) return;
        lst.push_back(now);
        dfs(now->left, lst);
        dfs(now->right, lst);
    }
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> lst;
        dfs(root, lst);
        TreeNode* tail = NULL;
        lst.push_back(tail);
        for (int i = 0; i < lst.size() - 1; i++) {
            lst[i]->left = NULL;
            lst[i]->right = lst[i+1];
        }
    }
};