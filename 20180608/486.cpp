class Solution {
public:
    int fdp(int l, int r, vector<vector<int>>& dp, vector<int>& tot) {
        if (dp[l][r] != -1) return dp[l][r];
        return dp[l][r] = tot[r]-(l==0?0:tot[l-1]) + max(-fdp(l+1,r,dp,tot),-fdp(l,r-1,dp,tot));
    }
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        vector<int> tot(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            dp[i][i] = nums[i];
            tot[i] = nums[i] + (i?tot[i-1]:0);
        }
        return fdp(0,nums.size()-1,dp,tot)*2 >= tot[nums.size()-1];
    }
};