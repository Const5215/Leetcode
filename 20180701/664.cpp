class Solution {
public:
    int fdp(string &s, vector<vector<int>>& dp, int L, int R) {
        if (L > R)
            return 0;
        if (dp[L][R])
            return dp[L][R];
        dp[L][R] = fdp(s, dp, L, R-1)+1;
        for (int i = L; i < R; i++)
            if (s[i] == s[R])
                dp[L][R] = min(dp[L][R], fdp(s, dp, L, i)+fdp(s, dp, i+1, R-1));
        return dp[L][R];
    }
    int strangePrinter(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        return fdp(s, dp, 0 , s.size()-1);
    }
};