class Solution {
public:
    int fdp(vector<vector<int>>& dp, vector<int>& s, int l, int r) {
        if (dp[l][r]) 
            return dp[l][r];
        if (l == r) 
            return dp[l][r] = s[l+1]-s[l];
        return dp[l][r] = s[r+1]-s[l]-min(fdp(dp, s, l+1, r), fdp(dp, s, l, r-1));
    }
    bool stoneGame(vector<int>& piles) {
        vector<int> s(piles.size()+1, 0);
        for (int i = 1; i <= piles.size(); i++)
            s[i] = s[i-1] + piles[i-1];
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size(), 0));
        return 2*fdp(dp, s, 0, piles.size()-1) > s[piles.size()+1];
    }
};