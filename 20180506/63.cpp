class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> ths(n);
        ths[0] = 1;
        for (int i = 0; i < m; i++) {
            vector<int> nxt(n);
            if (obstacleGrid[i][0] == 0) nxt[0] = ths[0];
            for (int j = 1; j < n; j++)
                if (obstacleGrid[i][j] == 0)
                    nxt[j] = nxt[j-1] + ths[j];
            ths = nxt;
        }
        return ths[n-1];
    }
};