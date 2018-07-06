bool cmp(pair<int, string>& a, pair<int, string>& b) {
    return a.first > b.first || (a.first == b.first && a.second < b.second);
}
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m;
        vector<pair<int, string>> tmp;
        vector<string> res;
        for (string ths : words)
            m[ths]++;
        for (auto it : m)
            tmp.push_back({it.second, it.first});
        sort(tmp.begin(), tmp.end(), cmp);
        for (int i = 0; i < k; i++)
            res.push_back(tmp[i].second);
        return res;
    }
};