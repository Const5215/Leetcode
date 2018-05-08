class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode* res = head->next ? head->next : head, *ths = head;
        while (ths && ths->next) {
            ListNode* nxt = ths->next->next;
            ths->next->next = ths;
            if (nxt && nxt->next)
                ths->next = nxt->next;
            else if (nxt)
                ths->next = nxt;
            else
                ths->next = NULL;
            ths = nxt;
        }
        return res;
    }
};