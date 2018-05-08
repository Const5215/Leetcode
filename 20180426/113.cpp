class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res = findpath(root, sum);
        for (auto &p : res)
            reverse(p.begin(), p.end());
        return res;
    }
private:
    vector<vector<int>> findpath(TreeNode* now, int sum) {
        vector<vector<int>> ths;
        if (now == NULL) return ths;
        if (now->left == NULL && now->right == NULL && now->val == sum) {
            vector<int> ini(1,sum);
            ths.push_back(ini);
            return ths;
        }
        if (now->left) {
            auto ls = findpath(now->left, sum-now->val);
            for (auto p : ls) {
                p.push_back(now->val);
                ths.push_back(p);
            }
        }
        if (now->right) {
            auto rs = findpath(now->right, sum-now->val);
            for (auto p : rs) {
                p.push_back(now->val);
                ths.push_back(p);
            }
        }
        return ths;
    }
};