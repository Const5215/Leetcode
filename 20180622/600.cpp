class Solution {
public:
    int fdp(vector<vector<vector<int>>>& dp, vector<int>& b, int len, int top, int bef) {
        if (len < 0) return 1;
        if (dp[len][top][bef] >= 0)
            return dp[len][top][bef];
        dp[len][top][bef] = 0;
        if (top) {
            if (b[len] == 0)
                return dp[len][top][bef] = fdp(dp, b, len-1, 1, 0);
            else {
                dp[len][top][bef] += fdp(dp, b, len-1, 0, 0);
                if (bef == 0)
                    dp[len][top][bef] += fdp(dp, b, len-1, 1, 1);
                return dp[len][top][bef];
            }
        }
        else {
            dp[len][top][bef] += fdp(dp, b, len-1, 0, 0);
            if (bef == 0)
                dp[len][top][bef] += fdp(dp, b, len-1, 0, 1);
            return dp[len][top][bef];
        }
    }
    int findIntegers(int num) {
        vector<int> b(32);
        vector<vector<vector<int>>> dp(32, vector<vector<int>>(2, vector<int>(2, -1)));
        for (int i = 0; i < 32; i++) {
            if (num & 1)
                b[i] = 1;
            num >>= 1;
        }
        return fdp(dp, b, 31, 1, 0);
    }
};