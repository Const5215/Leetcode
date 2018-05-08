class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dir[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        int x = board.size();
        int y = board[0].size();
        for (int i = 0; i < x; i++)
            for (int j = 0; j < y; j++) {
                int cnt = 0;
                for (int k = 0; k < 8; k++) {
                    int a = i+dir[k][0], b = j+dir[k][1];
                    if (a<0||a>=x||b<0||b>=y) continue;
                    if (board[a][b]&1) cnt++;
                }
                if (cnt==3) board[i][j] |= 2;
                if ((board[i][j]&1)&&(cnt==2)) board[i][j] |= 2; 
            }
        for (int i = 0; i < x; i++)
            for (int j = 0; j < y; j++)
                board[i][j]>>=1;
    }
};