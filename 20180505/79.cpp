class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || board[0].size() == 0) return false;
        int x = board.size(), y = board[0].size();
        for (int r = 0 ; r < x; r++)
            for (int c = 0; c < y; c++) {
                vector<vector<bool>> used(x, vector<bool>(y));
                if (board[r][c] == word[0] && find(board,used,word,r,c,1)) return true;
            }
        return false;
    }
private:
    bool find(const vector<vector<char>>& board, vector<vector<bool>>& used, const string& word, int r, int c, int now) {
        if (now == word.length()) return true;
        used[r][c] = 1;
        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        for (int d = 0 ; d < 4; d++) {
            int nx = r+dir[d][0],ny = c+dir[d][1];
            if (nx>=0 && nx < board.size() && ny >= 0 && ny < board[0].size() && !used[nx][ny] && board[nx][ny] == word[now]){
                if (find(board, used, word, nx, ny, now+1)) return true;
            }
        }
        used[r][c] = 0;
        return false;
    }
};