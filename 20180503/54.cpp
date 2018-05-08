class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0) return res;
        const int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        int chkbnd[4] = {1,1,1,2};
        int d=0,sz=matrix[0].size()*matrix.size();
        int x=0, y=0;
        while(res.size() < sz) {
            res.push_back(matrix[x][y]);
            int nx = x + dir[d][0]*chkbnd[d];
            int ny = y + dir[d][1]*chkbnd[d];
            while(res.size() < sz && (nx < 0 || ny < 0 || nx >= matrix.size() || ny >= matrix[0].size())) {
                chkbnd[d]++;
                d = (d+1)%4;
                nx = x + dir[d][0]*chkbnd[d];
                ny = y + dir[d][1]*chkbnd[d];
            }
            x = x+dir[d][0];
            y = y+dir[d][1];
        }
        return res;
    }
};