class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        if (matrix.size()) {
            vector<long long> ths(matrix[0].size()+1);
            this->s.push_back(ths);
        }
        for (auto now : matrix) {
            vector<long long> ths;
            ths.push_back(0);
            for (int i = 0; i < now.size(); i++) {
                ths.push_back(ths[i]+now[i]);
            }
            this->s.push_back(ths);
        }
        for (int i = 1; i < this->s.size(); i++)
            for (int j = 0; j < this->s[i].size(); j++)
                this->s[i][j] += this->s[i-1][j];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return (int)(this->s[row2+1][col2+1]-this->s[row1][col2+1]-this->s[row2+1][col1]+this->s[row1][col1]);
    }
private:
    vector<vector<long long>> s;
};