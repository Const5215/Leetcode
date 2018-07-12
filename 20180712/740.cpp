class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> p(10001);
        for (int x : nums)
            p[x] += x;
        vector<vector<int>> dp(10001, vector<int>(2,0));
        for (int i = 1; i <= 10000; i++) {
            dp[i][1] = max(dp[i][1], dp[i-1][1]);
            dp[i][1] = max(dp[i][1], dp[i-1][0]);
            dp[i][0] = max(dp[i][0], dp[i-1][1]+p[i]);
        }
        return max(dp[10000][0], dp[10000][1]);
    }
};