class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> rline(grid.size()),cline(grid[0].size());
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++) {
                rline[i] = max(rline[i], grid[i][j]);
                cline[j] = max(cline[j], grid[i][j]);
            }
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++) {
                res += min(rline[i],cline[j])-grid[i][j];
            }
        return res;
    }
};