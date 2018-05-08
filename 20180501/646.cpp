class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        set<int> num;
        for (int i = 0; i < pairs.size(); i++) {
            num.insert(pairs[i][0]);
            num.insert(pairs[i][1]);
        }
        unordered_map<int,int> m;
        int now = 0;
        for (int it : num)
            m[it] = ++now;
        vector<int> dp(2001, 0);
        for (auto ths : pairs) {
            int n = dp[m[ths[0]]-1]+1;
            for (int i = m[ths[1]]; i <= 2000; i++)
                dp[i] = max(dp[i], n);
        }
        return dp[2000];
    }
};