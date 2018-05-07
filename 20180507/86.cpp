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
    ListNode* partition(ListNode* head, int x) {
        ListNode* le = NULL, *head_le = NULL, *before = NULL;
        for (ListNode* now = head; now; now = now->next) {
            while (now && now->val >= x) {
                if (le) le->next = now;
                else head_le = now;
                le = now;
                if (before) before->next = now->next;
                else head = now->next;
                now = now->next;
            }
            if (now) before = now;
            else break;
        }
        if (le) le->next = NULL;
        if (before) {
            before->next = head_le;
            return head;
        }
        else return head_le;
    }
};