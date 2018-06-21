class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if (ops.size() == 0)
            return m*n;
        int a = INT_MAX, b = INT_MAX;
        for (auto ths : ops){
            a = min(a, ths[0]);
            b = min(b, ths[1]);
        }
        return a*b;
    }
};