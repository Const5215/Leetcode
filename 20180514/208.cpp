struct TrieNode {
    bool tail;
    vector<TrieNode*> nxt;
    TrieNode() : tail(false), nxt(26,NULL) {}
};
class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode* head = NULL;
    Trie() {
        head = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* now = head;
        for (int i = 0; i < word.length(); i++) {
            if (now->nxt[word[i]-'a'] == NULL) 
                now->nxt[word[i]-'a'] = new TrieNode();
            now = now->nxt[word[i]-'a'];
        }
        now->tail = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* now = head;
        for (int i = 0; i < word.length(); i++) {
            if (now->nxt[word[i]-'a'] == NULL) return false;
            now = now->nxt[word[i]-'a'];
        }
        return now->tail;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* now = head;
        for (int i = 0; i < prefix.length(); i++) {
            if (now->nxt[prefix[i]-'a'] == NULL) return false;
            now = now->nxt[prefix[i]-'a'];
        }
        return true;        
    }
};