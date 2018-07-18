class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        K++;
        vector<vector<int>> val(n, vector<int>(K+1, INT_MAX));
        vector<vector<pair<int, int>>> mp(n);
        for (auto it : flights)
            mp[it[0]].push_back({it[1],it[2]});
        queue<pair<int,int>> q;
        q.push({src, 0});
        val[src][0] = 0;
        while(q.size()) {
            auto now = q.front();
            q.pop();
            for (auto nxt : mp[now.first]) {
                if (val[nxt.first][now.second+1] > val[now.first][now.second] + nxt.second) {
                    for (int i = now.second+1; i <= K; i++)
                        val[nxt.first][i] = val[now.first][now.second] + nxt.second;
                        q.push({nxt.first, now.second+1});
                }
            }
        }
        int res = val[dst][K];
        return res == INT_MAX? -1: res;
    }
};