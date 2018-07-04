class Solution {
public:
    int find(vector<int>& uset, int i) {
        if (uset[i] == i) return i;
        return uset[i] = find(uset, uset[i]);
    }
    void union_set(vector<int>& uset, int i, int j) {
        uset[find(uset, i)] = uset[find(uset, j)];
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> uset(edges.size()+1);
        vector<int> ind(edges.size()+1,0);
        for (int now = edges.size()-1; now >= 0; now--) {
            for (int i = 1; i <= edges.size(); i++) {
                uset[i] = i;
                ind[i] = 0;
            }
            bool f = true;
            for (int i = 0; i < edges.size(); i++) {
                if (now == i) continue;
                if (++ind[edges[i][1]] >= 2 || find(uset, edges[i][0]) == find(uset, edges[i][1])) {
                    f = 0;
                    break;
                }
                union_set(uset, edges[i][0], edges[i][1]);
            }
            if (f)
                return edges[now];
        }
    }
};