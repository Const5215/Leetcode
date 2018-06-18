class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int, int> m;
        for (auto ths : wall){
            int now = 0, sz = ths.size()-1;
            for (int i = 0; i < sz; i++) {
                now += ths[i];
                m[now]++;
            }
        }
        int res = 0;
        for (auto it : m)
            res = max(res, it.second);
        return wall.size()-res;
    }
};