class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        dp.assign(nums.size(), vector<int>(nums.size(),-1) );
        return fdp(0, nums.size()-1, nums);
    }
private:
    vector<vector<int>> dp;
    int fdp(int L, int R, vector<int>& nums){
        if (R-L == 1) return 0;
        if (dp[L][R] != -1) return dp[L][R];
        for (int i = L+1 ; i <= R-1; i++) {
            int now = fdp(L,i,nums)+nums[L]*nums[i]*nums[R]+fdp(i,R,nums);
            dp[L][R] = max(dp[L][R], now);
        }
        return dp[L][R];
    }
};