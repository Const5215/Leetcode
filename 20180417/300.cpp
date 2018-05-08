class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for (int i : nums) {
            auto p = lower_bound(dp.begin(), dp.end(), i);
            if (p == dp.end()) dp.push_back(i);
            else dp[p-dp.begin()] = i;
        }
        return dp.size();
    }
};