class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();
        if (n == 0) return;
        for (int i = 0 ; i < m; i++){
            if (board[i][0] == 'O') ff(i,0,board);
            if (board[i][n-1] == 'O') ff(i,n-1,board);
        }
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') ff(0,i,board);
            if (board[m-1][i] == 'O') ff(m-1,i,board);
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == '.') board[i][j] = 'O';
                else board[i][j] = 'X';
    }
private:
    const int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    void ff(int x, int y, vector<vector<char>>& board) {
        board[x][y] = '.';
        for (int d = 0; d < 4; d++) {
            int nx = x+dir[d][0];
            int ny = y+dir[d][1];
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && board[nx][ny] == 'O')
                ff(nx, ny, board);
        }
    }
};