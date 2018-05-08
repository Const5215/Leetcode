class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        int p = matrix[0].size()-1;
        for (int i = 0 ; i < matrix.size(); i++) {
            while(p>=0 && matrix[i][p] > target) p--;
            if (p<0) return false;
            if (matrix[i][p] == target) return true;
        }
        return false;
    }
};