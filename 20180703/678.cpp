class Solution {
public:
    int fdp(vector<vector<int>>& dp, const string& s, int L, int R) {
        if (L > R)
            return true;
        if (dp[L][R] != -1)
            return dp[L][R];
        if (s[L] == ')' || s[R] == '(')
            return dp[L][R] = 0;
        dp[L][R] = 0;
        if (fdp(dp, s, L+1, R-1))
            return dp[L][R] = 1;
        if (s[R] == '*' && fdp(dp, s, L, R-1))
            return dp[L][R] = 1;
        if (s[L] == '*' && fdp(dp, s, L+1, R))
            return dp[L][R] = 1;
        for (int k = L+1; k+1 < R; k++)
            if (fdp(dp, s, L, k) && fdp(dp, s, k+1,R))
                return dp[L][R] =1;
        return dp[L][R];
    }
    bool checkValidString(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return fdp(dp, s, 0 ,s.size()-1) == 1;
    }
};