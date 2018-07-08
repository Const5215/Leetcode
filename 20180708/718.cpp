class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int>> dp(A.size(), vector<int>(B.size(), 0));
        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < B.size(); j++)
                if (A[i] == B[j])
                    dp[i][j] = max(((i>0&&j>0)?dp[i-1][j-1]:0)+1, dp[i][j]);
        int res = 0;
        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < B.size(); j++)
                res = max(res, dp[i][j]);
        return res;
    }
};