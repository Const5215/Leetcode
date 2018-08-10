class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        vector<pair<int, int>> lst(quiet.size());
        for (int i = 0; i < quiet.size(); i++)
            lst[i] = {quiet[i], i};
        vector<vector<int>> nxt(quiet.size());
        vector<int> ind(quiet.size());
        for (int i = 0; i < richer.size(); i++) {
            nxt[richer[i][0]].push_back(richer[i][1]);
            ind[richer[i][1]]++;
        }
        vector<int> res(quiet.size());
        queue<int> q;
        for (int i = 0; i < quiet.size(); i++)
            if (ind[i] == 0)
                q.push(i);
        while(q.size()) {
            int now = q.front();
            q.pop();
            for (int v : nxt[now]) {
                if (lst[v].first > lst[now].first)
                    lst[v] = lst[now];
                ind[v]--;
                if (ind[v] == 0)
                    q.push(v);
            }
        }
        for (int i = 0; i < quiet.size(); i++)
            res[i] = lst[i].second;
        return res;
    }
};