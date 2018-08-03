class Solution {
public:
    int find(vector<int>& uset, int now) {
        return now == uset[now] ? now: uset[now] = find(uset, uset[now]);
    }
    void union_set(vector<int>& uset, int a, int b) {
        uset[find(uset, a)] = uset[find(uset, b)];
    }
    int numSimilarGroups(vector<string>& A) {
        vector<int> uset(A.size());
        for (int i = 0; i < A.size(); i++)
            uset[i] = i;
        for (int i = 0; i < A.size(); i++)
            for (int j = i+1; j < A.size(); j++) {
                int p = -1, f = 1;
                for (int x = 0; x < A[i].size(); x++)
                    if (A[i][x] != A[j][x]) {
                        if (p == -1)
                            p = x;
                        else if (A[i][x] != A[j][p] || A[i][p] != A[j][x]){
                            f = 0;
                            break;
                        }
                    }
                if (f)
                    union_set(uset, i, j);
            }
        int res = 0;
        vector<bool> vis(A.size());
        for (int i = 0; i < A.size(); i++)
            if (!vis[find(uset, i)]) {
                vis[find(uset, i)] = 1;
                res++;
            }
        return res;
    }
};