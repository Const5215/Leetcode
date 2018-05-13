class Solution {
public:
    int countPrimes(int n) {
        vector<bool> flag(n+1);
        vector<int> primes;
        for (int i = 2; i < n; i++) {
            if (flag[i] == 0) primes.push_back(i);
            for (int j = 0; i*primes[j] <= n; j++) {
                flag[i*primes[j]] = 1;
                if (i % primes[j] == 0) break;
            }
        }
        return primes.size();
    }
};