class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int,int>> res;
        if (matrix.size() == 0 || matrix[0].size() == 0) return res;
        queue<pair<int, int>> q;
        vector<vector<int>> vis(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix[0].size(); i++) {
            q.push(make_pair(0,i));
            vis[0][i] = 2;
        }
        for (int i = 1; i < matrix.size(); i++) {
            q.push(make_pair(i,0));
            vis[i][0] = 2;
        }
        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        while(q.size()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + dir[d][0];
                int ny = y + dir[d][1];
                if (nx < 0 || ny < 0 || nx >= matrix.size() || ny >= matrix[0].size() || vis[nx][ny] || matrix[nx][ny] < matrix[x][y])
                    continue;
                vis[nx][ny] = 2;
                q.push(make_pair(nx,ny));
            }
        }
        for (int i = 0; i < matrix[0].size(); i++) {
            q.push(make_pair(matrix.size()-1,i));
            vis[matrix.size()-1][i]--;
        }
        for (int i = 0; i < matrix.size()-1; i++) {
            q.push(make_pair(i,matrix[0].size()-1));
            vis[i][matrix[0].size()-1]--;
        }
        while(q.size()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + dir[d][0];
                int ny = y + dir[d][1];
                if (nx < 0 || ny < 0 || nx >= matrix.size() || ny >= matrix[0].size() || vis[nx][ny] == 1 || vis[nx][ny] == -1 || matrix[nx][ny] < matrix[x][y])
                    continue;
                vis[nx][ny]--;
                q.push(make_pair(nx,ny));
            }
        }
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++)
                if (vis[i][j] == 1)
                    res.push_back(make_pair(i,j));
        return res;
    }
};