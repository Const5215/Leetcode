class Solution {
int s[1<<20]={};
public:
    bool dp(int cnt, int tot, int stat) {
        if (tot <= 0) return false;
        if (s[stat]) return s[stat] == 1;
        for (int i = 0; i < cnt; i++){
            if (stat&1<<i) continue;
            if (dp(cnt, tot-i-1, stat|(1<<i))==false) {
                s[stat] = 1;
                return true;
            }
        }
        s[stat] = -1;
        return false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal < 2) return true;
        int sum = (maxChoosableInteger+1)*maxChoosableInteger/2;
        if (sum < desiredTotal) return false;
        if (sum == desiredTotal) return maxChoosableInteger%2;
        return dp(maxChoosableInteger, desiredTotal, 0);
    }
};