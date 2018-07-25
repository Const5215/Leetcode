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
    int numComponents(ListNode* head, vector<int>& G) {
        set<int> s;
        for (int x : G)
            s.insert(x);
        int res = 0;bool vis = false;
        for (; head != NULL; head = head->next) {
            if (s.find(head->val) != s.end()) {
                if (vis == false) {
                    vis = true;
                    res++;
                }
            }
            else
                vis = false;
        }
        return res;
    }
};