class Solution {
public:
    double myPow(double x, int n) {
        double res = 1, ths = n>=0 ? x : (1/x);
        long long k = n == INT_MIN ? 1ll<<31 : abs(n);
        for (;k;k>>=1) {
            if (k&1) res *= ths;
            ths *= ths;
        }
        return res;
    }
};