class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int L = 0, R = piles[0];
        for (int pile : piles)
            R = max(pile, R);
        while(R-L > 1) {
            int m = (R-L)/2+L, now = 0;
            for (int pile : piles)
                now += pile/m + (pile % m ? 1: 0);
            if (now > H)
                L = m;
            else 
                R = m;
        }
        return R;
    }
};