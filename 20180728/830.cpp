class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;
        int l = 0, r = 0;
        while(l < S.size()) {
            r = l+1;
            while(r < S.size() && S[r-1] == S[r])
                r++;
            if (r-l >= 3)
                res.push_back({l,r-1});
            l = r;
        }
        return res;
    }
};