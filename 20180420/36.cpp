class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i <= 8; i++)
        {
            int cnt = 0;
            for (int j = 0; j<= 8; j++)
                if (board[i][j]!='.') {
                    int num = board[i][j]-'0';
                    if (cnt&(1<<num)) return false;
                    cnt |= (1<<num);
                }
        }
        for (int i = 0; i <= 8; i++)
        {
            int cnt = 0;
            for (int j = 0; j<= 8; j++)
                if (board[j][i]!='.') {
                    int num = board[j][i]-'0';
                    if (cnt&(1<<num)) return false;
                    cnt |= (1<<num);
                }
        }
        for (int i = 0; i <= 8; i++)
        {
            int cnt = 0;
            for (int j = 0; j<= 8; j++)
                if (board[i/3*3+j/3][i%3*3+j%3]!='.') {
                    int num = board[i/3*3+j/3][i%3*3+j%3]-'0';
                    if (cnt&(1<<num)) return false;
                    cnt |= (1<<num);
                }
        }
        return true;
    }
};