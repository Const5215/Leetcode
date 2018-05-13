class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m,r;
        for (int i = 0; i < s.length(); i++) {
            if (m[s[i]] == 0) m[s[i]] = t[i];
            else if (m[s[i]] != t[i]) return false;
            if (r[t[i]] == 0) r[t[i]] = s[i];
            else if (r[t[i]] != s[i]) return false;
        }
        return true;
    }
};