class Solution {
public:
    int flipLights(int n, int m) {
        set<vector<bool>> s;
        for (int i = 0; i < 16; i++) {
            if ((__builtin_popcount(i)&1) != (m&1) || m < __builtin_popcount(i))
                continue;
            vector<bool> stat(n,1);
            if (i&1) {
                for (int i = 0; i < n; i++)
                    stat[i]=!stat[i];
            }
            if (i&2) {
                for (int i = 1; i < n; i+=2)
                    stat[i]=!stat[i];
            }
            if (i&4) {
                for (int i = 0; i < n; i+=2)
                    stat[i]=!stat[i];               
            }
            if (i&8) {
                for (int i = 0; i < n; i+=3)
                    stat[i]=!stat[i];               
            }
            s.insert(stat);
        }
        return s.size();
    }
};