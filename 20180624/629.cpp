class Solution {
public:
    int kInversePairs(int n, int k) {
        if (k == 0)
            return 1;
        if (n == 1)
            return 0;
        int md = 1e9+7;
        vector<int> ths(k+1);
        ths[0] = 1;ths[1] = 1;
        for (int i = 3;i <= n; i++) {
            vector<int> nxt(k+1);
            int now = 0;
            for(int p = 0; p <= k; p++) {
                now += ths[p];
                if (p >= i)
                    now -= ths[p-i];
                now %= md;
                if (now < 0)
                    now += md;
                nxt[p] = now;
            }
            ths = nxt;
        }
        return ths[k];
    }
};