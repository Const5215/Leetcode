class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        unordered_map<int, int> mp;
        return helper(price, special, mp, get_key(needs));
    }
private:
    int helper(vector<int>& price, vector<vector<int>>& special, unordered_map<int, int>& mp, int k) {
        if (mp.count(k))
            return mp[k];
        int n = price.size(), ans = 0;
        int now = k;
        for (int i = price.size()-1; i >= 0; i--) {
            ans += price[i]*(now%10);
            now /= 10;
        }
        for (auto spe:special) {
            vector<int> tmp(price.size());
            int now = k;
            bool f = 1;
            for (int i = price.size()-1; i >= 0; i--) {
                tmp[i] = (now%10)-spe[i];
                if (tmp[i] < 0) {
                    f = 0;
                    break;
                }
                now /= 10;
            }
            if (f)
                ans = min(ans, spe[n]+helper(price, special, mp, get_key(tmp)));
        }
        return mp[k] = ans;
    }
    int get_key(const vector<int>& needs) {
        int key = 0;
        for (int x : needs)
            key = key*10+x;
        return key;
    }
};