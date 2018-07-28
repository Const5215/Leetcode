class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int l = 0, r = 0, res = 0;
        for (int i = 0; i < ages.size(); i++) {
            while(r < ages.size() && ages[r] <= ages[i])
                r++;
            while(l < ages.size() && ages[l] <= ages[i]/2+7)
                l++;
            if (r > l)
                res += (r-l);
            if (l <= i && r > i)
                res--;
        }
        return res;
    }
};