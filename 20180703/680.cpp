class Solution {
public:
    bool validPalindrome(string s) {
        for(int L = 0, R = s.size()-1; L <= R; L++,R--)
            if(s[L]!=s[R]){
                int LL = L+1, LR = R;
                while(LL <= LR && s[LL] == s[LR]) {
                    LL++;
                    LR--;
                }
                if(LL>=LR)
                    return true;
                int RL = L, RR = R-1;
                while(RL <= RR && s[RL] == s[RR]) {
                    RL++;
                    RR--;
                }
                if(RL>=RR)
                    return true;
                return false;
            }
        return true;
    }
};