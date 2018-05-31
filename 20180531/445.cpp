class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> a,b;
        for (auto i = l1; i; i = i->next) a.push(i);
        for (auto i = l2; i; i = i->next) b.push(i);
        int m = 0;
        ListNode* head = NULL;
        while(a.size() && b.size()) {
            ListNode* ths = new ListNode(a.top()->val+b.top()->val+m);
            m = ths->val/10;
            ths->val %= 10;
            ths->next = head;
            head = ths;
            a.pop();b.pop();
        }
        if (a.size()) {
            while(a.size()) {
                ListNode* ths = new ListNode(a.top()->val+m);
                m = ths->val/10;
                ths->val %= 10;
                ths->next = head;
                head = ths;
                a.pop();
            }
        } else {
            while(b.size()) {
                ListNode* ths = new ListNode(b.top()->val+m);
                m = ths->val/10;
                ths->val %= 10;
                ths->next = head;
                head = ths;
                b.pop();
            }            
        }
        if (m) {
            ListNode* ths = new ListNode(m);
            ths->next = head;
            head = ths;
        }
        return head;
    }
};