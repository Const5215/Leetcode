class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<set<vector<int>>> dp(target+1);
        vector<int> ini;
        dp[0].insert(ini);
        for (int now : candidates) {
            vector<set<vector<int>>> nxt = dp;
            for (int i = 0 ; i <= target - now; i++) {
                for (auto it : dp[i]) {
                    auto tmp = it;
                    tmp.push_back(now);
                    nxt[i+now].insert(tmp);
                }
            }
            dp = nxt;
        }
        vector<vector<int>> res(dp[target].begin(), dp[target].end());
        return res;
    }
};