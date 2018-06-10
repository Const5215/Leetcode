class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return res;
        for (int k = 0; k < matrix.size()+matrix[0].size()-1; k++)
            for (int x = 0 ; x <= k; x++)
                if (k&1) {
                    if (x < matrix.size() && (k-x) < matrix[0].size())
                        res.push_back(matrix[x][k-x]);
                }
                else {
                    if ((k-x) < matrix.size() && x < matrix[0].size())
                        res.push_back(matrix[k-x][x]);
                }
        return res;
    }
};