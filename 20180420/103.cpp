class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) q.push(root);
        vector<vector<int>> res;
        while(q.size()) {
            vector<int> ths;
            queue<TreeNode*> n;
            for(; q.size(); q.pop()) {
                ths.push_back(q.front()->val);
                if (q.front()->left) n.push(q.front()->left);
                if (q.front()->right) n.push(q.front()->right);
            }
            res.push_back(ths);
            q = n;
        }
        for (int i = 1; i < res.size(); i+=2)
            reverse(res[i].begin(),res[i].end());
        return res;
    }
};