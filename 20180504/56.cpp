bool cmp (const Interval &a, const Interval &b) {
    return a.end < b.end;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> res;
        if (intervals.size() == 0) return res;
        Interval new_interval = intervals[intervals.size()-1];
        for (int i = intervals.size()-2; i >= 0; i--) {
            if (intervals[i].end < new_interval.start) {
                res.push_back(new_interval);
                new_interval = intervals[i];
            }
            else {
                new_interval.start = min(new_interval.start, intervals[i].start);
            }
        }
        res.push_back(new_interval);
        reverse(res.begin(),res.end());
        return res;
    }
};