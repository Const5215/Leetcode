class Solution {
public:
    const int md = 100000007;
    int qadd(int a, int b) {
        int res = 0, tmp = a;
        for (; b; b >>= 1) {
            if (b&1) {
                res += tmp;
                res %= md;
            }
            tmp += tmp;
            tmp %= md;
        }
        return res;
    }
    int uniqueLetterString(string S) {
        vector<int> L(S.size()), R(S.size());
        vector<int> last(26, 0);
        for (int i = 0; i < S.size(); i++) {
            L[i] = last[S[i]-'A'];
            last[S[i]-'A'] = i+1;
        }
        for (int i = 0; i < 26; i++)
            last[i] = S.size()-1;
        for (int i = S.size()-1; i >= 0; i--) {
            R[i] = last[S[i]-'A'];
            last[S[i]-'A'] = i-1;
        }
        int res = 0;
        for (int i = 0; i < S.size(); i++) {
            int lx = i-L[i]+1, rx = R[i]-i+1;
            res += qadd(lx,rx);
            res %= md;
        }
        return res;
    }
};