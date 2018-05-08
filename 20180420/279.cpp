class Solution {
public:
    int numSquares(int n) {
        vector<int> res;
        for (int i = 0; i <= n ;i++) res.push_back(i);
        for (int k = 2; k*k <= n; k++) {
            int s = k*k;
            for (int p = s; p <= n; p ++)
                res[p] = min(res[p], res[p-s]+1);
        }
        return res[n];
    }
};