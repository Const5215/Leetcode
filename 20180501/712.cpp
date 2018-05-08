class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int x = s1.size(), y = s2.size();
        vector<vector<int>> dp(x+1, vector<int>(y+1, 1<<30));
        dp[0][0] = 0;
        for (int i = 0; i <= x; i++)
            for (int j = 0; j <= y;j++)
                if (i < x && j < y && s1[i] == s2[j]) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
                else {
                    if (i < x) dp[i+1][j] = min(dp[i+1][j],dp[i][j]+(int)s1[i]);
                    if (j < y) dp[i][j+1] = min(dp[i][j+1],dp[i][j]+(int)s2[j]);
                }
        return dp[x][y];
    }
};