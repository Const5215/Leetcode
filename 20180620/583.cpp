class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.length() == 0 || word2.length() == 0)
            return word1.length()+word2.length();
        vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), 0));
        for (int i = 0; i < word1.length(); i++)
            for (int j = 0; j < word2.length();j++){
                if (word1[i] == word2[j])
                    dp[i][j] = max(dp[i][j], ((i > 0 && j > 0)?dp[i-1][j-1]:0)+1);
                if (i > 0)
                    dp[i][j] = max(dp[i][j], dp[i-1][j]);
                if (j > 0)
                    dp[i][j] = max(dp[i][j], dp[i][j-1]);
            }
        return word1.length()+word2.length()-dp[word1.length()-1][word2.length()-1]*2;
    }
};