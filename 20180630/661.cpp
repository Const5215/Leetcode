class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> res(M.size(), vector<int>(M[0].size(), 0));
        int dir[9][2] = {{0,0},{0,1},{0,-1},{1,0},{1,-1},{1,1},{-1,-1},{-1,0},{-1,1}};
        for (int i = 0; i < M.size(); i++)
            for (int j = 0; j < M[0].size(); j++) {
                int cnt = 0;
                for (int d = 0; d < 9; d++) {
                    int ni = i + dir[d][0];
                    int nj = j + dir[d][1];
                    if (ni < 0 || ni >= M.size() || nj < 0 || nj >= M[0].size())
                        continue;
                    cnt++;
                    res[i][j] += M[ni][nj];
                }
                res[i][j] = floor((double)res[i][j]/cnt);
            }
        return res;
    }
};