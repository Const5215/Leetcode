class Solution {
public:
    int reachNumber(int target) {
        long long t = abs(target);
        long long tmp = ceil((sqrt(1+8*t)-1)/2);
        while ((tmp*(tmp+1)/2-t)%2)
            tmp++;
        return (int)tmp;
    }
};