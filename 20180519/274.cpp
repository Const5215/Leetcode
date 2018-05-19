class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int res = 0, sz = citations.size();
        for (int i = 0; i < sz; i++)
            res = max(res, min(citations[i], sz-i));
        return res;
    }
};