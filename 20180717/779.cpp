class Solution {
public:
    int kthGrammar(int N, int K) {
        int res = 0;
        K--;
        for (;K;K>>=1)
            if (K&1)
                res ^= 1;
        return res;
    }
};