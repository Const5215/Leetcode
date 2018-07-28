class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int res = 0;
        for (int i = 1; i*(i+1) <= N*2; i++) {
            if (i%2 == 1 && N % i == 0)
                res++;
            if (i%2 == 0 && (N+i/2) % i == 0)
                res++;
        }
        return res;
    }
};