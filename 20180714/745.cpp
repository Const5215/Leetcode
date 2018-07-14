struct TrieNode {
    vector<int> s;
    vector<TrieNode*> nxt;
    TrieNode() : nxt(vector<TrieNode*>(26, NULL)) {}
};
class WordFilter {
public:
    TrieNode *head, *rhead;
    WordFilter(vector<string> words) {
        head = new TrieNode(), rhead = new TrieNode();
        for (int i = 0; i < words.size(); i++) {
            string now = words[i];
            TrieNode *ths = head;
            for (char x : now) {
                ths->s.push_back(i);
                if (ths->nxt[x-'a'] == NULL)
                    ths->nxt[x-'a'] = new TrieNode();
                ths = ths->nxt[x-'a'];
            }
            ths->s.push_back(i);
            reverse(now.begin(), now.end());
            ths = rhead;
            for (char x : now) {
                ths->s.push_back(i);
                if (ths->nxt[x-'a'] == NULL)
                    ths->nxt[x-'a'] = new TrieNode();
                ths = ths->nxt[x-'a'];
            }
            ths->s.push_back(i);
        }
    }
    
    int f(string prefix, string suffix) {
        reverse(suffix.begin(), suffix.end());
        vector<int> p,q;
        TrieNode *ths = head;
        for (char x : prefix) {
            ths = ths->nxt[x-'a'];
            if (ths == NULL)
                break;
        }
        if (ths == NULL)
            return -1;
        p = ths->s;
        ths = rhead;
        for (char x : suffix) {
            ths = ths->nxt[x-'a'];
            if (ths == NULL)
                break;
        }
        if (ths == NULL)
            return -1;
        q = ths->s;
        auto x = p.rbegin(), y = q.rbegin();
        while(x != p.rend() && y != q.rend()) {
            if (*x == *y)
                return *x;
            else if (*x > *y)
                x++;
            else
                y++;
        }    
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */