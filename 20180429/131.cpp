class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> tmp(s.length());
        for (double i = 0 ; i < s.size(); i+= 0.5) {
            if (i-((int)i) > 1e-6) tmp[(int)i].push_back(s.substr((int)i,1));
            for (int d = 1;; d++) {
                int L = ceil(i-d), R = floor(i+d);
                if (L < 0 || R>= s.size() || s[L] != s[R]) break;
                tmp[L].push_back(s.substr(L,R-L+1));
            }
        }
        return find(s, tmp, 0);
    }
private:
    vector<vector<string>> find(string &s, vector<vector<string>> &data,int now) {
        vector<vector<string>> ths;
        
        if (now == s.length()) {
            vector<string> ini;
            ths.push_back(ini);
            return ths;
        }
        for (auto x : data[now]) {
            auto tmp = find(s, data, now+x.length());
            for (auto it : tmp) {
                it.insert(it.begin(),x);
                ths.push_back(it);
            }
        }
        return ths;
    }
};