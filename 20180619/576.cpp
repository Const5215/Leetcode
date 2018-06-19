class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<int>> dp(m, vector<int>(n,0));
        dp[i][j] = 1;
        int res = 0;
        int md = 1e9+7;
        while(N--) {
            vector<vector<int>> nxt(m, vector<int>(n,0));
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++) {
                    for (int d = 0; d < 4; d++) {
                        int nx = i + dir[d][0], ny = j + dir[d][1];
                        if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                            res += dp[i][j];
                            res %= md;
                        }
                        else {
                            nxt[nx][ny] += dp[i][j];
                            nxt[nx][ny] %= md;
                        }
                    }
                }
            dp = nxt;
        }
        return res;
    }
};