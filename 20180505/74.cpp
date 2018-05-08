class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int l = 0, r = matrix.size()-1;
        while(r-l > 1) {
            int m = (r-l)/2+l;
            if (matrix[m][0] > target) r = m;
            else l = m;
        }
        if (matrix[r][0] <= target) l = r;
        int a = 0, b = matrix[0].size()-1;
        while(b-a >1) {
            int m = (b-a)/2+a;
            if (matrix[l][m] > target) b = m;
            else a = m;
        }
        return matrix[l][a] == target || matrix[l][b] == target;
    }
};