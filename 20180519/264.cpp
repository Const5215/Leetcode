class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> s;
        s.insert(1);
        for (int i = 1; i < n; i++) {
            long long now = *s.begin();
            s.erase(now);
            s.insert(now*2);
            s.insert(now*3);
            s.insert(now*5);
        }
        return (int)*s.begin();
    }
};