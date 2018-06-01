class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        return sumP(root, 0, sum)+pathSum(root->left, sum)+pathSum(root->right, sum);
    }
private:
    int sumP(TreeNode* root, int now, int& sum) {
        if (root == NULL) return 0;
        return (root->val+now == sum)+sumP(root->left, root->val+now, sum)+sumP(root->right, root->val+now, sum);
    }
};