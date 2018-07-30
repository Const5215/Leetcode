class Solution {
public:
    int find_c(vector<int>& lst, vector<vector<int>>& mp, int now) {
        lst[now] = 1;
        for (int nxt : mp[now])
            if (lst[nxt] == -1)
                lst[now] += find_c(lst, mp, nxt);
        return lst[now];
    }
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<vector<int>> mp(N);
        for (auto edge : edges) {
            mp[edge[0]].push_back(edge[1]);
            mp[edge[1]].push_back(edge[0]);
        }
        vector<int> c(N, -1);
        find_c(c, mp, 0);
        vector<int> res(N);
        queue<pair<int, int>> q;
        vector<bool> vis(N, false);
        vis[0] = true;
        q.push({0,0});
        while(q.size()) {
            auto now = q.front();q.pop();
            for (int nxt : mp[now.first])
                if (!vis[nxt]) {
                    vis[nxt] = true;
                    res[0] += now.second+1;
                    q.push({nxt, now.second+1});
                }
        }
        queue<int> p;
        vis[0] = false;
        p.push(0);
        while(p.size()) {
            int now = p.front();p.pop();
            for (int nxt : mp[now])
                if (vis[nxt]) {
                    vis[nxt] = false;
                    res[nxt] = res[now]+N-2*c[nxt];
                    p.push(nxt);
                }
        }
        return res;
    }
};