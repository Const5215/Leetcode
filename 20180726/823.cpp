class Solution {
public:
    const int md = 1000000007;
    int qadd(int a, int b) {
        int ths = 0, tmp = a;
        for (; b; b >>= 1) {
            if (b & 1) {
                ths = ths + tmp;
                ths %= md;
            }
            tmp *= 2;
            tmp %= md;
        }
        return ths;
    }
    int numFactoredBinaryTrees(vector<int>& A) {
        sort(A.begin(), A.end());
        map<int, int> m;
        for (int i = 0; i < A.size(); i++)
            m[A[i]] = i;
        vector<vector<pair<int, int>>> lst(A.size());
        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < i; j++)
                if (A[i]%A[j] == 0) {
                    auto it = m.find(A[i]/A[j]);
                    if (it != m.end())
                        lst[i].push_back({it->second, j});
                }
        vector<int> cnt(A.size(), 1);
        int res = 0;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < lst[i].size(); j++) {
                cnt[i] += qadd(cnt[lst[i][j].first], cnt[lst[i][j].second]);
                cnt[i] %= md;
            }
            res += cnt[i];
            res %= md;
        }
        return res;
    }
};