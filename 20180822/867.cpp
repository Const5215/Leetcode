class Solution {
public:
    int binaryGap(int N) {
        bool pst = false;
        int cnt = 1, res = 0;
        for(;N;N >>= 1) {
            if (N&1) {
                if (pst)
                    res = max(res, cnt);
                pst = true;cnt = 1;
            }
            else
                cnt++;       
        }
        return res;
    }
};