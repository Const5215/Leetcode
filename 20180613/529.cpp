class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        pair<int,int> c = {click[0], click[1]};
        if (board[c.first][c.second] == 'M') {
            board[c.first][c.second] = 'X';
            return board;
        }
        int dir[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1}};
        int x = board.size(), y = board[0].size();
        queue<pair<int,int>> q;
        q.push(c);
        while(q.size()) {
            int a = q.front().first, b = q.front().second;
            q.pop();
            int cnt = 0;
            for (int i = 0; i < 8; i++) {
                int nx = a+dir[i][0], ny = b+dir[i][1];
                if (nx<0||nx>=x||ny<0||ny>=y) continue;
                if (board[nx][ny] == 'M') cnt++;
            }
            if (cnt == 0) {
                board[a][b] = 'B';
                for (int i = 0; i < 8; i++) {
                    int nx = a+dir[i][0], ny = b+dir[i][1];
                    if (nx<0||nx>=x||ny<0||ny>=y) continue;
                    if (board[nx][ny] == 'E') {
                        board[nx][ny] = 'B';
                        q.push({nx,ny});
                    }
                }
            }
            else {
                board[a][b] = (char)('0'+cnt);
            }
        }
        return board;
    }
};