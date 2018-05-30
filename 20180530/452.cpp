class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        sort(points.begin(), points.end());
        int i = 0,res = 0;
        while(i < points.size()) {
            res++;
            int now = i, loc = points[i].second;
            while(now < points.size() && points[now].first <= loc) {
                now++;
                loc = min(loc, points[now].second);
            }
            i = now;
        }
        return res;
    }
};