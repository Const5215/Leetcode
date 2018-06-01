class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (s.size() < p.size()) return res;
        map<char,int> m;
        for (char x : p) m[x]--;
        int cnt = 0;
        for (auto it : m) cnt++;
        for (int i = 0; i < p.size(); i++) {
            m[s[i]]++;
            if (m[s[i]] == 0) cnt--;
            if (m[s[i]] == 1) cnt++;
        }
        for (int i = 0; i < s.size()-p.size(); i++) {
            if (cnt == 0) res.push_back(i);
            m[s[i+p.size()]]++;
            if (m[s[i+p.size()]] == 0) cnt--;
            if (m[s[i+p.size()]] == 1) cnt++;
            m[s[i]]--;
            if (m[s[i]] == 0) cnt--;
            if (m[s[i]] == -1) cnt++;
        }
        if (cnt == 0) res.push_back(s.size()-p.size());
        return res;
    }
};