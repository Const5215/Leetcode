class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.length() <= 1) return s;
        vector<int> nxt = getnxt(s);
        string rev(s.rbegin(), s.rend());
        int id = 0;
        for (int i = 0; i < rev.length(); i++) {
            if (s[id] == rev[i])
                id++;
            else {
                while(id && s[id] != rev[i])
                    id = nxt[id-1];
                if (s[id] == rev[i])
                    id++;
            }
        }
        return rev + s.substr(id);
    }
private:
    vector<int> getnxt(string s) {
        vector<int> nxt(s.length());
        nxt[0] = 0;
        int id = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s[id] == s[i]) {
                nxt[i] = nxt[i-1]+1;
                id++;
            }
            else {
                while(id && s[id] != s[i])
                    id = nxt[id-1];
                if (s[id] == s[i])
                    id++;
                nxt[i] = id;
            }
        }
        return nxt;
    }
};