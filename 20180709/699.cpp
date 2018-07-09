class Solution {
public:
    vector<int> fallingSquares(vector<pair<int, int>>& positions) {
        set<int> s;
        map<int ,int> m;
        for (int i = 0; i < positions.size(); i++) {
            s.insert(positions[i].first);
            s.insert(positions[i].first+positions[i].second);
        }
        int cnt = 0;
        for (auto it : s)
            m[it] = cnt++;
        vector<int> mx(cnt-1);
        vector<int> res;
        int ths = 0;
        for (int i = 0; i < positions.size(); i++) {
            int l = m[positions[i].first], r = m[positions[i].first+positions[i].second];
            int h = 0;
            for (int j = l; j < r; j++)
                h = max(mx[j], h);
            ths = max(ths, h+positions[i].second);
            for (int j = l; j < r; j++)
                mx[j] = h+positions[i].second;
            res.push_back(ths);
        }
        return res;
    }
};