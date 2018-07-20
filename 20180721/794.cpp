class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int cntx = 0, cnto = 0;
        for (string line : board) 
            for (char x : line)
                if (x == 'X')
                    cntx++;
                else if (x == 'O')
                    cnto++;
        bool fx = 0, fo = 0;
        for(int i = 0; i < 3; i++) {
            if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O')
                fo = 1;
            if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O')
                fo = 1;
        }
        if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
            fo = 1;
        if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
            fo = 1;
        for(int i = 0; i < 3; i++) {
            if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X')
                fx = 1;
            if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X')
                fx = 1;
        }
        if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
            fx = 1;
        if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
            fx = 1;
        if (fo && fx)
            return false;
        if (fo)
            return cnto == cntx;
        if (fx)
            return cnto+1 == cntx;
        return
            (cnto == cntx) || (cnto+1 == cntx);
    }
};