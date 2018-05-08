class Solution {
public:
    int integerBreak(int n) {
        vector<int> maxprod(n+1, 1);
        for(int i = 2; i <= n; i++)
            for(int j = 1; j < i; j++)
                maxprod[i] = max(maxprod[i], max(maxprod[j] * (i - j), j * (i - j)));
        return maxprod[n];
    }
};