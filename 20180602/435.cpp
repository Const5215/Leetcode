bool cmp(Interval a ,Interval b) {
    return a.start < b.start || a.start == b.start && a.end < b.end;
}

class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int res = 0;
        int i = 0;
        for (;i < intervals.size();) {
            int r = intervals[i].end;
            int j = i+1;
            for(;j < intervals.size() && intervals[j].start < r; j++) {
                res++;
                r = min(r, intervals[j].end);
            }
            i = j;
        }
        return res;
    }
};