bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int L = 0, R = n;
        while(R-L > 1) {
            int m  = (R-L)/2+L;
            if (isBadVersion(m)) R = m;
            else L = m;
        }
        return R;
    }
};