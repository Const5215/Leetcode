class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = m&n;
        for (int i = 1; i != INT_MIN; i<<=1) {
            if (n-m >= i) res &= (~i);
        }
        return res;
    }
};