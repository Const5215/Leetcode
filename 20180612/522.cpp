class Solution {
public:
    bool findsub(const string &s, const string &t) {
        int p = 0;
        for (int i = 0;p < t.size() && i < s.size(); i++) {
            if (s[i] == t[p])
                p++;
        }
        return p == t.size();
    }
    int findLUSlength(vector<string>& lst) {
        int res = -1;
        for (int i = 0; i < lst.size(); i++) {
            bool f = 1;
            for (int j = 0; j < lst.size(); j++) {
                if (i == j) continue;
                if (findsub(lst[j], lst[i]))  {
                    f = 0;
                    break;
                }
            }
            if (f)
                res = max(res, (int)lst[i].length());
        }
        return res;
    }
};