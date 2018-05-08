class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * before = NULL;
        for (ListNode* now = head; now; now = now->next) {
            if (now->next && now->val == now->next->val) {
                while(now->next && now->val == now->next->val) {
                    now->next = now->next->next;
                }
                if (head == now) head = now->next;
                if (before) before->next = now->next;
            }
            else before = now;
        }
        return head;
    }
};