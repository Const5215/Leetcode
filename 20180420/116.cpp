class Solution {
public:
    void connect(TreeLinkNode *root) {
        connectR(root);
        for (auto it = root; it ;it = it->right)
            it->next = NULL;
    }
private:
    void connectR(TreeLinkNode *root) {
        if (root == NULL || root->left == NULL) return;
        if (tmp) {
            TreeLinkNode* x = tmp->next;
            tmp->next = root->left;
            tmp = x;
        }
        root->left->next = root->right;
        connectR(root->left);
        connectR(root->right);
        root->right->next = tmp;
        tmp = root->right;
    }
    TreeLinkNode* tmp = NULL;
};