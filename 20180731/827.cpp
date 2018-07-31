class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int label = 1;
        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        map<int,int> m;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == 1) {
                    label++;
                    queue<pair<int,int>> q;
                    grid[i][j] = label;m[label]++;
                    q.push({i,j});
                    while(q.size()) {
                        auto now = q.front();q.pop();
                        for (int d = 0; d < 4; d++){
                            int ni = now.first+dir[d][0], nj = now.second+dir[d][1];
                            if (ni >= 0 && ni < grid.size() && nj >= 0 && nj< grid[0].size() && grid[ni][nj] == 1){
                                grid[ni][nj] = label;m[label]++;
                                q.push({ni, nj});
                            }
                        }
                    } 
                }
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] > 0)
                    res = max(res, m[grid[i][j]]);
                else {
                    int now = 1;
                    set<int> vis;
                    for (int d = 0; d < 4; d++) {
                        int ni = i+dir[d][0], nj = j+dir[d][1];
                        if (ni >= 0 && ni < grid.size() && nj >= 0 && nj< grid[0].size() && grid[ni][nj] && vis.count(grid[ni][nj]) == 0){                               vis.insert(grid[ni][nj]);
                            now += m[grid[ni][nj]];
                        }
                    }
                    res = max(res, now);
                }
        return res;
    }
};