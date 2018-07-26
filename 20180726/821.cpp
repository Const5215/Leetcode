class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int p = 20000;
        vector<int> l(S.size()), r(S.size()) ,res(S.size());
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == C)
                p = 0;
            else
                p++;
            l[i] = p;
        }
        p = 20000;
        for (int i = S.size()-1; i >= 0; i--) {
            if (S[i] == C)
                p = 0;
            else
                p++;
            r[i] = p;
        }
        for (int i = 0; i < S.size(); i++)
            res[i] = min(l[i], r[i]);
        return res;
    }
};