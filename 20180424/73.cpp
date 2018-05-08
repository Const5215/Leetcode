class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool r0 = false, c0 = false;
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0 ; j < matrix[0].size(); j++)
                if (matrix[i][j] == 0) {
                    if (i == 0) r0 = true;
                    if (j == 0) c0 = true;
                    matrix[i][0]=matrix[0][j]=0;
                }
        for (int i = 1; i < matrix.size(); i++)
            if (matrix[i][0] == 0) 
                for (int j = 0;j < matrix[0].size(); j++)
                    matrix[i][j] = 0;
        for (int j = 1;j < matrix[0].size(); j++)
            if (matrix[0][j] == 0)
                for (int i = 0; i < matrix.size(); i++)
                    matrix[i][j] = 0;
        if (r0)
            for (int j = 0;j < matrix[0].size(); j++)
                matrix[0][j] = 0;
        if (c0)
            for (int i = 0; i < matrix.size(); i++)
                matrix[i][0] = 0;
    }
};