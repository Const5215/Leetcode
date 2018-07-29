class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> res;
        for (auto ths : A) {
            reverse(ths.begin(), ths.end());
            for (int i = 0; i < ths.size(); i++)
                ths[i] = ths[i]^1;
            res.push_back(ths);
        }
        return res;
    }
};