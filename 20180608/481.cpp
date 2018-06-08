class Solution {
public:
    int magicalString(int n) {
        if (n == 0) return 0;
        if (n < 3) return 1;
        n-=3;
        string s = "122";
        int f = 0;
        int p = 2;
        while(n) {
            s += (char)('1'+f);
            if (--n == 0) break;
            if (s[p] == '2') {
                s += (char)('1'+f);
                n--;
            }
            f ^= 1;
            p++;
        }
        int res = 0;
        for (char x : s)
            if (x == '1') res++;
        return res;
    }
};