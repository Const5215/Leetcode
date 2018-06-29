class Solution {
public:
    int minSteps(int n) {
        int t = n;
        int res = 0;
        for (int i = 2; i <= t; i++)
            while (n%i == 0) {
                n /= i;
                res += i;
            }
        return res;
    }
};