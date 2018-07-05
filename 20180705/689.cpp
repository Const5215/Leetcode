class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(4,0));
        vector<int> sub(1,0);
        for (int i = 0; i < nums.size(); i++)
            sub.push_back(sub[i]+nums[i]-(i >= k?nums[i-k]:0));
        vector<vector<vector<int>>> rec(nums.size()+1, vector<vector<int>>(4, vector<int>(3,0)));
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 0 ; j < 4; j++) { 
                dp[i][j] = dp[i-1][j];
                rec[i][j] = rec[i-1][j];
                if (i >= k && j > 0 && dp[i][j] < dp[i-k][j-1] + sub[i]) {
                    dp[i][j] = dp[i-k][j-1] + sub[i];
                    rec[i][j] = rec[i-k][j-1];
                    rec[i][j][j-1] = i-k;
                }
            }
        }
        return rec[nums.size()][3];
    }
};