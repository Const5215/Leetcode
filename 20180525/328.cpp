class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) return head;
        ListNode* o = head, *e = head->next, *n = head->next;
        while(o->next && o->next->next) {
            o->next = o->next->next;
            e->next = e->next->next;
            o = o->next;
            e = e->next;
        }
        o->next = n;
        return head;
    }
};