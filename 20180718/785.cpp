class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> col(graph.size(),-1);
        queue<int> q;
        for (int i = 0; i < graph.size(); i++){
            if (col[i] == -1) {
                q.push(i);
                col[i] = 0;
                while(q.size()) {
                    int now = q.front();q.pop();
                    for (int i = 0; i < graph[now].size(); i++)
                        if (col[graph[now][i]] == col[now])
                            return false;
                        else if (col[graph[now][i]] == -1) {
                            col[graph[now][i]] = col[now]^1;
                            q.push(graph[now][i]);
                        }
                }
            }
        }
        return true;
    }
};