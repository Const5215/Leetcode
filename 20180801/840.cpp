class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < (int)grid.size()-2; i++)
            for (int j = 0; j < (int)grid[0].size()-2; j++) {
                vector<bool> vis(10);
                for (int x = 0; x < 3; x++)
                    for (int y = 0; y < 3; y++)
                        if (grid[i+x][j+y] >= 10 || grid[i+x][j+y] == 0) {
                            vis[0] = 1;break;
                        } else {
                            vis[grid[i+x][j+y]] = 1;
                        }
                for (int i = 1; i <= 9; i++)
                    if (!vis[i])
                        vis[0] = 1;
                if (vis[0])
                    continue;
                int now = grid[i][j] + grid[i][j+1] + grid[i][j+2];
                if (grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2] != now)
                    continue;
                if (grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2] != now)
                    continue;
                if (grid[i][j] + grid[i+1][j] + grid[i+2][j] != now)
                    continue;
                if (grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1] != now)
                    continue;
                if (grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2] != now)
                    continue;
                if (grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2] != now)
                    continue;
                if (grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2] != now)
                    continue;
                res++;
            }
        return res;
    }
};