class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        vector<int> dest(1000000,-1);
        map<int, vector<int>> m;
        for (int i = 0; i < routes.size(); i++)
            for (int j = 0; j < routes[i].size(); j++)
                m[routes[i][j]].push_back(i);
        queue<int> q;
        vector<bool> vis(1000000);
        vector<bool> vis_route(501);
        dest[S] = 0;vis[S] = 1;q.push(S);
        while(q.size()) {
            int now = q.front();q.pop();
            for (int nxt_route : m[now]) {
                if (vis_route[nxt_route])
                    continue;
                vis_route[nxt_route] = 1;
                for (int nxt : routes[nxt_route])
                    if (!vis[nxt]) {
                        vis[nxt] = 1;
                        dest[nxt] = dest[now] + 1;
                        q.push(nxt);
                    }
            }
        }
        return dest[T];
    }
};