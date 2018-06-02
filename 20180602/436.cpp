class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        set<pair<int, int>> s;
        vector<int> res;
        for (int i = 0; i < intervals.size(); i++)
            s.insert(make_pair(intervals[i].start, i));
        for (int i = 0; i < intervals.size(); i++) {
            auto pos = s.lower_bound(make_pair(intervals[i].end, -1));
            if (pos != s.end()) res.push_back(pos->second);
            else res.push_back(-1);
        }
        return res;
    }
};