class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return construct(head, NULL);
    }
private:
    TreeNode* construct(ListNode* L, ListNode* R) {
        if (L == NULL || L == R) return NULL;
        if (L->next == R) {
            TreeNode* ths = new TreeNode(L->val);
            return ths;
        }
        ListNode *slow = L, *fast = L;
        while(fast != R && fast->next != R && fast->next->next != R) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* ths = new TreeNode(slow->val);
        ths->left = construct(L, slow);
        ths->right = construct(slow->next, R);
        return ths;
    }
};