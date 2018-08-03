class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int s = 0, t = 0;
        for (int i = 0; i < S.size(); i++)
            if (S[i] != '#')
                S[s++] = S[i];
            else if (s > 0)
                s--;
        for (int i = 0; i < T.size(); i++)
            if (T[i] != '#')
                T[t++] = T[i];
            else if (t > 0)
                t--;
        return S.substr(0,s) == T.substr(0,t);
    }
};