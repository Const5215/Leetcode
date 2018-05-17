class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> p, res;
        multiset<int> h;
        for (auto &now : buildings) {
            p.push_back(make_pair(now[0],-now[2]));
            p.push_back(make_pair(now[1],now[2]));
        }
        sort(p.begin(),p.end());
        h.insert(0);
        int pre = 0;
        for (auto &now : p) {
            if (now.second < 0 ) h.insert(-now.second);
            else h.erase(h.find(now.second));
            int cur = *h.rbegin();
            if (cur != pre)
                res.push_back(make_pair(now.first,cur));
            pre = cur;
        }
        return res;
    }
};