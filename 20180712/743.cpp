class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int, int>>> edge(N+1);
        for (auto now : times) {
            edge[now[0]].push_back({now[1], now[2]});
        }
        queue<int> q;
        vector<int> dir(N+1, INT_MAX);
        vector<bool> inq(N+1);
        dir[K] = 0;
        q.push(K);
        inq[K] = 1;
        while(q.size()) {
            int p = q.front();
            q.pop();inq[p] = 0;
            for (auto now : edge[p])
                if (dir[p]+now.second < dir[now.first]) {
                    dir[now.first] = dir[p]+now.second;
                    if (!inq[now.first]) {
                        inq[now.first] = 1;
                        q.push(now.first);
                    }
                }
        }
        int res = 0;
        for (int i = 1; i <= N; i++)
            res = max(res, dir[i]);
        return res == INT_MAX?-1:res;
    }
};