class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<bool>> m(N, vector<bool>(N, true));
        for (auto it : mines)
            m[it[0]][it[1]] = false;
        vector<vector<int>> u(N, vector<int>(N, 0));
        vector<vector<int>> d = u, l = u , r = u;
        for (int i = 0;i < N; i++)
            for (int j = 0; j < N; j++) {
                u[i][j] = i == 0 || m[i-1][j] == false? 0: u[i-1][j]+1;
                l[i][j] = j == 0 || m[i][j-1] == false? 0: l[i][j-1]+1;
            }
        for (int i = N-1;i >= 0; i--)
            for (int j = N-1; j >= 0; j--) {
                d[i][j] = i == N-1 || m[i+1][j] == false? 0: d[i+1][j]+1;
                r[i][j] = j == N-1 || m[i][j+1] == false? 0: r[i][j+1]+1;
            }
        int res = 0;
        for (int i = 0;i < N; i++)
            for (int j = 0; j < N; j++) {
                if (m[i][j] == false)
                    continue;
                res = max(res, min(u[i][j], min(d[i][j], min(l[i][j], r[i][j])))+1);
            }
        return res;
    }
};