class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        queue<pair<int,int>> q;
        int x = matrix.size(), y = matrix[0].size();
        for (int i = 0; i < x; i++)
            for (int j = 0; j < y; j++)
                if (matrix[i][j] == 0) {
                    q.push({i,j});
                }
                else {
                    matrix[i][j] = INT_MAX;
                }
        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        while(q.size()) {
            int a = q.front().first, b = q.front().second;
            q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = a+dir[d][0], ny = b+dir[d][1];
                if (nx < 0 || nx >= x || ny < 0 || ny >= y)
                    continue;
                if (matrix[a][b]+1 < matrix[nx][ny]) {
                    matrix[nx][ny] = matrix[a][b]+1;
                    q.push({nx,ny});   
                }
            }
        }
        return matrix;
    }
};