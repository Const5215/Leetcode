class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        set<int> s(primes.begin(),primes.end());
        s.insert(1);
        while(--n) {
            int now = *s.begin();
            s.erase(s.begin());
            for (int x : primes) {
                long long nxt = (long long)now * x;
                if (nxt <= INT_MAX) s.insert((int)nxt);
            }
        }
        return *s.begin();
    }
};