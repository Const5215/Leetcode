class Solution {
public:
    int checkRecord(int n) {
        vector<int> v(6),x(6);
        v[0] = 1;
        int m = 1e9+7;
        while(n--) {
            x[0] = 0;
            x[0] += v[0];x[0] %= m;
            x[0] += v[1];x[0] %= m;
            x[0] += v[2];x[0] %= m;
            x[1] = v[0];
            x[2] = v[1];
            x[3] = 0;
            x[3] += v[0];x[3] %= m;
            x[3] += v[1];x[3] %= m;
            x[3] += v[2];x[3] %= m;
            x[3] += v[3];x[3] %= m;
            x[3] += v[4];x[3] %= m;
            x[3] += v[5];x[3] %= m;
            x[4] = v[3];
            x[5] = v[4];
            v = x;
        }
        int res = 0;
        for (int ths : v){
            res += ths;
            res %= m;
        }
        return res;
    }
};