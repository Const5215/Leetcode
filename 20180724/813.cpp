class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        vector<double> tot(A.size()+1);
        for (int i = 1; i <= A.size(); i++)
            tot[i] = tot[i-1] + A[i-1];
        vector<vector<double>> dp(A.size()+1, vector<double>(K,-1));
        dp[0][0] = 0;
        for (int i = 1; i <= A.size(); i++) {
            dp[i][0] = tot[i]/i;
            for (int j = 1; j < K; j++)
                for (int p = 0; p < i; p++) {
                    if (dp[p][j-1] < 0)
                        continue;
                    if (dp[i][j] < 0)
                        dp[i][j] = dp[p][j-1] + (tot[i]-tot[p])/(i-p);
                    else
                        dp[i][j] = max(dp[i][j], dp[p][j-1] + (tot[i]-tot[p])/(i-p));
                }
        }
        double res = 0;
        for (int i = 0; i < K; i++)
            res = max(res, dp[A.size()][i]);
        return res;
    }
};