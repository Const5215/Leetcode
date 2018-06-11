class Solution {
public:
    int fdp(int l, int r,vector<vector<int>>& dp,string& s) {
        if (l > r) return 0;
        if (l == r) return 1;
        if (dp[l][r] != -1) return dp[l][r];
        if (s[l] == s[r])
            dp[l][r] = max(dp[l][r], fdp(l+1, r-1, dp, s)+2);
        dp[l][r] = max(dp[l][r], fdp(l+1, r, dp, s));
        dp[l][r] = max(dp[l][r], fdp(l, r-1, dp, s));
        return dp[l][r];
    }
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(),-1));
        return fdp(0,s.size()-1,dp,s);
    }
};