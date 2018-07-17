class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int> m;
        int res = 0;
        for (int x : answers) {
            if (m[x] == x+1) {
                m[x] = 0;
                res += x+1;
            }
            m[x]++;
        }
        for (auto x : m)
            res += x.first+1;
        return res;
    }
};