class Solution {
public:
    int trailingZeroes(int n) {
        long long k = 5;
        int res = 0;
        for(; k<=n; k*=5) {
            res += n/k;
        }
        return res;
    }
};