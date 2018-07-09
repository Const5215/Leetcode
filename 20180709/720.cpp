struct TrieNode {
    vector<TrieNode*> nxt;
    bool f;
    TrieNode(bool tmp) : f(tmp), nxt(vector<TrieNode*>(26,NULL)) {}
};
class Solution {
public:
    string res = "";
    void find(TrieNode* pts, string tmp) {
        if (tmp.size() > res.size() || tmp < res)
            res = tmp;
        for (int i = 0; i < 26; i++)
            if (pts->nxt[i] != NULL && pts->nxt[i]->f)
                find(pts->nxt[i], tmp + (char)(i+'a'));
    }
    string longestWord(vector<string>& words) {
        TrieNode* head = new TrieNode(true);
        for (string now : words) {
            TrieNode* ths = head;
            for (char x : now) {
                if (ths->nxt[x-'a'] == NULL)
                    ths->nxt[x-'a'] = new TrieNode(false);
                ths = ths->nxt[x-'a'];
            }
            ths->f = true;
        }
        string tmp = "";
        find(head, tmp);
        return res;
    }
};