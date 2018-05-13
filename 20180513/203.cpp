class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val == val) head = head->next;
        if (head == NULL) return head;
        ListNode* before = head;
        for (ListNode* now = head->next; now; now = now->next) {
            if (now->val == val) before->next = now->next;
            else before = now;
        }
        return head;
    }
};