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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        queue<int> q;
        ListNode* tmp = root;
        for (;tmp;tmp = tmp->next)
            q.push(tmp->val);
        int tot = q.size();
        vector<ListNode*> res(k, NULL);
        for (int i = 0; i < k; i++) {
            ListNode* tmp = NULL;
            for (int j = 0; j < (i<tot%k?tot/k+1:tot/k); j++){
                if (j) {
                    tmp->next = new ListNode(q.front());
                    tmp = tmp->next;
                }
                else {
                    res[i] = new ListNode(q.front());
                    tmp = res[i];
                }
                q.pop();
            }
        }
        return res;
    }
};