class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        priority_queue<pair<int, int>> q;
        for (int i : nums)
            m[i]++;
        for (auto it : m)
            q.push(make_pair(it.second, it.first));
        vector<int> res;
        while(k--) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};