class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> m;
        int res = 0;
        for (int x : nums) {
            m[x]++;
            if (m[x+1] != 0)
                res = max(res, m[x]+m[x+1]);
            if (m[x-1] != 0)
                res = max(res, m[x]+m[x-1]);
        }
        return res;
    }
};