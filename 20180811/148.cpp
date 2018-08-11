/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* f = head->next->next;
        ListNode* p = head;
        while (f != NULL && f->next != NULL) {
            p = p->next;
            f =  f->next->next;
        }
        ListNode* h2 = sortList(p->next);
        p->next = NULL;
        return merge(sortList(head), h2);
    }
    ListNode* merge(ListNode* h1, ListNode* h2) {
        ListNode* hn = new ListNode(INT_MIN);
        ListNode* c = hn;
        while (h1 != NULL && h2 != NULL) {
            if (h1->val < h2->val) {
                c->next = h1;
                h1 = h1->next;
            }
            else {
                c->next = h2;
                h2 = h2->next;
            }
            c = c->next;
        }
        if (h1 != NULL)
            c->next = h1;
        if (h2 != NULL)
            c->next = h2;
        return hn->next;
    }
};