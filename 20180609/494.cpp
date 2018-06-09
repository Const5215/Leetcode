class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int k = 0;
        for (int x : nums)
            k += x;
        k -= S;
        if ((k&1) || k < 0) return 0;
        k/=2;
        vector<int> dp(k+1);
        dp[0] = 1;
        for (int x : nums){
            vector<int> ndp = dp;
            for (int i = x; i <= k; i++)
                ndp[i] += dp[i-x];
            dp = ndp;
        }
        return dp[k];
    }
};