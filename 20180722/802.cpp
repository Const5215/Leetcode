class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> rgraph(graph.size());
        for (int i = 0; i < graph.size(); i++)
            for (int nxt : graph[i])
                rgraph[nxt].push_back(i);
        vector<int> ind(graph.size());
        queue<int> q;
        for (int i = 0; i < graph.size(); i++) {
            ind[i] = graph[i].size();
            if (ind[i] == 0) q.push(i);
        }
        while(q.size()) {
            int now = q.front();q.pop();
            for (int x : rgraph[now]) {
                ind[x]--;
                if (ind[x] == 0)
                    q.push(x);
            }
        }
        vector<int> res;
        for (int i = 0; i < graph.size(); i++)
            if (ind[i] == 0)
                res.push_back(i);
        return res;
    }
};