class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return 1;
        ListNode* slow = head, *fast = head, *before = NULL;
        while(fast && fast->next) {
            fast = fast->next->next;
            ListNode* tmp = slow->next;
            slow->next = before;
            before = slow;
            slow = tmp;
        }
        if (fast) slow = slow->next;
        while(slow) {
            if (slow->val != before->val) return false;
            slow = slow->next;
            before = before->next;
        }
        return true;
    }
};