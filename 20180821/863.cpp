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
    vector<int> res;
    int findtarget(TreeNode* root, TreeNode* target, int K) {
        if (root == NULL)
            return -1;
        if (root == target) {
            finddepth(root, K);
            return 1;
        }
        int a = findtarget(root->left, target, K), b = findtarget(root->right, target, K);
        if (a == -1 && b == -1)
            return -1;
        if (a == -1) {
            if (K == b) {
                res.push_back(root->val);
                return -1;
            }
            finddepth(root->left, K-b-1);
            return b+1;
        }
        else {
            if (K == a) {
                res.push_back(root->val);
                return -1;
            }
            finddepth(root->right, K-a-1);
            return a+1;
        }
        
    }
    void finddepth(TreeNode* root, int K) {
        if (root == NULL)
            return;
        if (K == 0) {
            res.push_back(root->val);
            return;
        }
        finddepth(root->left, K-1);
        finddepth(root->right, K-1);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        findtarget(root, target, K);
        return res;
    }
};