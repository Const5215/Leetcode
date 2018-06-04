class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s = 0;
        for (int i : nums) s += i;
        if (s&1) return false;
        s >>= 1;
        vector<bool> dp(s+1);
        dp[0] = 1;
        for (int i : nums) {
            vector<bool> nxt(s+1);
            if (i == 0)
                continue;
            for (int j = 0; j <= s; j++)
                nxt[j] = dp[j] || (j-i >= 0 && dp[j-i]);
            dp = nxt;
        }
        return dp[s];
    }
};