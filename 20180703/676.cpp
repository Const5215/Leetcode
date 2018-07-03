struct TrieNode {
    vector<TrieNode*> nxt;
    bool e;
    TrieNode(bool ths) : e(ths), nxt(vector<TrieNode*>(26,NULL)) {}
};
class MagicDictionary {
public:
    TrieNode* head = NULL;
    /** Initialize your data structure here. */
    MagicDictionary() {
        head = new TrieNode(false);
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (string now : dict) {
            TrieNode* p = head;
            for (char x : now) {
                if (p->nxt[x-'a'] == NULL)
                    p->nxt[x-'a'] = new TrieNode(false);
                p = p->nxt[x-'a'];
            }
            p->e = true;
        }
    }
    
    bool dfs(const string& word, int len, TrieNode* pts, bool chng) {
        if (pts == NULL)
            return false;
        if (chng) {
            if (pts->e && len == word.size())
                return true;
            if (len >= word.size())
                return false;
            return dfs(word, len+1, pts->nxt[word[len]-'a'], true);
        }
        else {
            if (len >= word.size())
                return false;
            for (int i = 0; i < 26; i++) {
                if (dfs(word, len+1, pts->nxt[i], word[len]-'a' != i) == true)
                    return true;
            }
        }
        return false;
    }
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        return dfs(word, 0, head, false);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */