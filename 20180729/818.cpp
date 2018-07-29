class Solution {
public:
    int racecar(int target) {
        vector<vector<int>> dp(10001, vector<int>(30, INT_MAX));
        dp[0][15] = 0;
        queue<pair<int, int>> q;
        q.push({0, 15});
        while(q.size()) {
            auto now = q.front();
            q.pop();
            int nxt = now.second < 15 ? now.first-(1<<(14-now.second)) : now.first+(1<<(now.second-15));
            if (nxt < 0 || nxt > 10000)
                continue;
            int nxt_v = now.second < 15 ? now.second-1 : now.second+1;
            if (nxt_v >= 0 && nxt_v <= 29 && dp[nxt][nxt_v] > dp[now.first][now.second] + 1) {
                dp[nxt][nxt_v] = dp[now.first][now.second] + 1;
                q.push({nxt, nxt_v});
            }
            nxt_v = now.second < 15 ? 15: 14;
            if (dp[now.first][nxt_v] > dp[now.first][now.second] + 1) {
                dp[now.first][nxt_v] = dp[now.first][now.second] + 1;
                q.push({now.first, nxt_v});                
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < 30; i++)
            res = min(res, dp[target][i]);
        return res;
    }
};