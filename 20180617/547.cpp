int find(vector<int>& s, int x) {
    if (s[x] == x) return x;
    else return s[x] = find(s, s[x]);
}
void union_set(vector<int>& s, int a, int b) {
    s[find(s,a)] = s[find(s,b)];
}
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<bool> vis(M.size());
        vector<int> s(M.size());
        for (int i = 0; i < M.size(); i++)
            s[i] = i;
        for (int i = 0; i < M.size(); i++)
            for (int j = i+1; j < M.size(); j++)
                if (M[i][j])
                    union_set(s,i,j);
        int res = 0;
        for (int i = 0; i < M.size(); i++)
            if (vis[find(s,s[i])] == 0) {
                vis[find(s,s[i])] = 1;
                res++;
            }
        return res;        
    }
};