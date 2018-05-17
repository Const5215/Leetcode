class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        int maxd = 0;
        for (auto now = root; now; now = now->left) maxd++;
        int L = 0, R = (1 << (maxd-1) );
        while(R-L > 1) {
            int m = (R-L)/2+L;
            if (find(root, maxd-1, m)) L = m;
            else R = m;
        }
        return (1<<(maxd-1))-1+L+1;
    }
private:
    bool find(TreeNode* node, int depth, int now) {
        for (int i = depth-1; i >= 0 ; i--) 
            if ((now>>i)&1) node = node->right;
            else node = node->left;
        return node != NULL;
    }
};