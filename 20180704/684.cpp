class Solution {
public:
    int find(vector<int>& uset, int i) {
        if (uset[i] == i) return i;
        return uset[i] = find(uset, uset[i]);
    }
    void union_set(vector<int>& uset, int i, int j) {
        uset[find(uset, i)] = uset[find(uset, j)];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> uset(edges.size()+1);
        for (int i = 0; i <= edges.size(); i++)
            uset[i] = i;
        for (int i = 0; i < edges.size(); i++) {
            if (find(uset, edges[i][0]) == find(uset, edges[i][1]))
                return edges[i];
            union_set(uset, edges[i][0] , edges[i][1]);
        }
    }
};