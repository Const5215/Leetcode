struct TrieNode{
    bool mk;
    vector<TrieNode*> nxt;
    TrieNode(bool f) : mk(f), nxt(vector<TrieNode*>(26,NULL)) {}
};
class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        TrieNode* head = new TrieNode(false);
        for (string now : dict) {
            TrieNode* ths = head;
            for (int i = 0; i < now.size(); i++){
                if (ths->nxt[now[i]-'a'] == NULL)
                    ths->nxt[now[i]-'a'] = new TrieNode(false);
                ths = ths->nxt[now[i]-'a'];
            }
            ths->mk = true;
        }
        istringstream iss(sentence);
        string res = "",tmp;
        while(iss>>tmp) {
            if (res != "")
                res = res + " ";
            TrieNode* ths = head;
            bool f = true;
            int i;
            for (i = 0; i < tmp.size(); i++) {
                if (ths->nxt[tmp[i]-'a'] == NULL)
                    break;
                ths = ths->nxt[tmp[i]-'a'];
                if (ths->mk == true) {
                    f = false;
                    break;
                }
            }
            if (f)
                res = res+tmp;
            else
                res = res+tmp.substr(0,i+1);
        }
        return res;
    }
};