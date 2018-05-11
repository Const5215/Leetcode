class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k > prices.size()) k = prices.size();
        if (prices.size() == 0 || k==0) return 0;
        vector<int> past0(k+1),past1(k+1,-prices[0]),ths0(k+1),ths1(k+1);
        past1[0] = 0;
        for (int i = 1; i < prices.size(); i++) {
            for (int t = 1; t <= k; t++) {
                ths0[t] = max(past0[t], past1[t]+prices[i]);
                ths1[t] = max(past1[t], past0[t-1]-prices[i]);
            }
            past0 = ths0;
            past1 = ths1;
        }
        int res = INT_MIN;
        for (int t = 0;t <= k; t++) res = max(res, past0[t]);
        return res;
    }
};