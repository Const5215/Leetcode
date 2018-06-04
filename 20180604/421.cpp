class node {
public:
    node *l = NULL, *r = NULL;
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        node *head = new node;
        for (int i : nums) {
            node *now = head;
            for (int j = 1<<30; j; j >>= 1) {
                if (i & j) {
                    if (!now->l)
                        now->l = new node;
                    now = now->l;
                }
                else {
                    if (!now->r)
                        now->r = new node;
                    now = now->r;
                }
            }
        }
        int res = 0;
        for (int i : nums) {
            node *now = head;
            int ths = 0;
            for (int j = 1<<30; j; j >>= 1) {
                if (i & j) {
                    if (now->r) {
                        ths |= j;
                        now = now->r;
                    }
                    else
                        now = now->l;
                }
                else {
                    if (now->l) {
                        ths |= j;
                        now = now->l;
                    }
                    else
                        now = now->r;
                }
                res = max(res, ths);
            }
        }
        return res;
    }
};