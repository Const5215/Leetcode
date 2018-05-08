class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> ths(1, triangle[0][0]);
        for (int i = 1 ; i < triangle.size(); i++) {
            vector<int> nxt(triangle[i].size(),0);
            nxt[0] = ths[0]+triangle[i][0];
            for (int j = 1; j < triangle[i].size()-1; j++) {
                nxt[j] = min(ths[j-1],ths[j]) + triangle[i][j];
            }
            nxt[nxt.size()-1] = ths[ths.size()-1] + triangle[i][nxt.size()-1];
            ths = nxt;
        }
        int res = ths[0];
        for (int x : ths)
            if (x < res) res = x;
        return res;
    }
};