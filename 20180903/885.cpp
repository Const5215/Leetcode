class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        int cnt = 0, vis = 0, r = r0, c = c0 , d = 0;
        vector<vector<int>> res;vector<int> loc(2);
        loc[0] = r;loc[1] = c;
        res.push_back(loc);
        vis++;
        while(vis < R*C) {
            for (int i = 0; i <= cnt/2; i++) {
                r = r + dir[d][0]; c = c + dir[d][1];
                if (r >= 0 && r < R && c >= 0 && c < C) {
                    loc[0] = r;loc[1] = c;
                    res.push_back(loc);
                    vis++;
                    if (vis == R*C) break;
                }
            }
            d = (d+1)%4;
            cnt++;
        }
        return res;
    }
};