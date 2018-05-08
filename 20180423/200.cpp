class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    res++;
                    queue<pair<int, int>> q;
                    q.push(make_pair(i,j));
                    while(q.size()) {
                        int x = q.front().first, y = q.front().second;
                        q.pop();
                        for (int d = 0 ; d < 4; d++) {
                            int nx = x + dir[d][0];
                            int ny = y + dir[d][1];
                            if (nx<0||nx>=grid.size()||ny<0||ny>=grid[0].size()) continue;
                            if (grid[nx][ny] == '1') {
                                grid[nx][ny] = '0';
                                q.push(make_pair(nx,ny));
                            } 
                        }
                    }
                }
        return res;
    }
};