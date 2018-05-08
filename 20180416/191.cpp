class Solution {
public:
    int hammingWeight(uint32_t n) {
        int x = n, res = 0;
        for (; x; x-=(x&(-x))) res++;
        return res;
    }
};