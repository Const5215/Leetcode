class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int res = 0;
        for (auto row : grid) {
            int mx = 0;
            for (int h : row) {
                if (h) res++;
                mx = max(mx, h);
            }
            res += mx;
        }
        for (int j = 0; j < grid[0].size(); j++) {
            int mx = 0;
            for (int i = 0; i < grid.size(); i++)
                mx = max(mx, grid[i][j]);
            res += mx;
        }
        return res;
    }
};