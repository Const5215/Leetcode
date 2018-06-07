class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        for (string ths : strs) {
            int z = 0,o = 0;
            for (char x : ths)
                if (x == '0') z++;
            o = ths.length()-z;
            vector<vector<int>> ndp = dp;
            for (int i = z;i <= m; i++)
                for (int j = o; j <= n; j++)
                    ndp[i][j] = max(dp[i][j],dp[i-z][j-o]+1);
            dp = ndp;
        }
        return dp[m][n];
    }
};