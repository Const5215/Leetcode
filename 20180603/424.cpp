class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        for (int i = 0; i < 26; i++) {
            char x = 'A'+i;
            int l = 0, r= 0 ,c = k;
            while (r < s.size() && (c || s[r] == x)){
                if (s[r] != x) c--;
                r++;
            }
            res = max(res, r-l);
            while(r < s.size()) {
                r++;
                while(r < s.size() && s[r] == x) r++;
                while(s[l] == x) l++;
                l++;
                res = max(res, r-l);
            }
        }
        return res;
    }
};