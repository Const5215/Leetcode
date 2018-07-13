class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        vector<int> dp(cost.size(), INT_MAX);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 0; i < cost.size(); i++) {
            dp[i+1] = min(dp[i+1], cost[i+1]+dp[i]);
            if (i+2 <= cost.size())
                dp[i+2] = min(dp[i+2], cost[i+2]+dp[i]);
        }
        return dp[cost.size()-1];
    }
};