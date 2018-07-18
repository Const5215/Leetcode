class Solution {
public:
    int rotatedDigits(int N) {
        int res = 0;
        for (int i = 1; i <= N; i++) {
            int now = i;
            bool p = true, q = false;
            for(;now;now/=10) {
                int d = now%10;
                if (d == 3 || d == 4 || d == 7) {
                    p = false;
                    break;
                }
                if (d == 2 || d == 5 || d == 6 || d == 9)
                    q = true;
            }
            if (p&&q)
                res++;
        }
        return res;
    }
};