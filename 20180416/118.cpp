class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows) {
            vector<int> ths;
            ths.push_back(1);
            res.push_back(ths);
        }
        for (int j = 1; j < numRows; j++) {
            vector<int> ths;
            int s = res[j-1].size();
            ths.push_back(1);
            for (int i = 1; i < s; i++)
                ths.push_back(res[j-1][i]+res[j-1][i-1]);
            ths.push_back(1);
            res.push_back(ths);
        }
        return res;
    }
};