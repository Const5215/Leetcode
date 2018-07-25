struct TrieNode {
    bool p;
    vector<TrieNode*> nxt;
    TrieNode() : p(false), nxt(vector<TrieNode*>(26, NULL)) {}
};
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        TrieNode* head = new TrieNode();
        for (string word : words) {
            reverse(word.begin(), word.end());
            TrieNode* now = head;
            for (char x : word) {
                if (now->nxt[x-'a'] == NULL)
                    now->nxt[x-'a'] = new TrieNode();
                now = now->nxt[x-'a'];
            }
            now->p = true;
        }
        queue<pair<TrieNode*,int>> q;
        q.push({head, 1});
        int res = 0;
        while(q.size()) {
            auto now = q.front(); q.pop();
            bool f = 0;
            for (int i = 0; i < 26; i++) {
                if (now.first->nxt[i] != NULL) {
                    f = 1;
                    q.push({now.first->nxt[i], now.second+1});
                }
            }
            if (f == 0 && now.first->p == true)
                res += now.second;
        }
        return res;
    }
};