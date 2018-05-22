class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int a = 0, b = INT_MIN, c = 0;
        for (int i = 0; i < prices.size(); i++) {
            int na = max(a, c);
            int nb = max(b, a-prices[i]);
            int nc = max(c, b+prices[i]);
            a = na;
            b = nb;
            c = nc;
        }
        return max(max(a,b),c);
    }
};