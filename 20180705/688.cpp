class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double>> board(N, vector<double>(N,0));
        board[r][c] = 1;
        double res;
        int dir[8][2] = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
        while(K--) {
            vector<vector<double>> nxt(N, vector<double>(N,0));
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++) {
                    for (int d = 0; d < 8; d++) {
                        int ni = i + dir[d][0];
                        int nj = j + dir[d][1];
                        if (ni < 0 || ni >= N || nj < 0 || nj >= N)
                            continue;
                        nxt[ni][nj] += board[i][j]*0.125;
                    }
                }
            board = nxt;
        }
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                res += board[i][j];
        return res;
    }
};