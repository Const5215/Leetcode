class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, res = 0, cnt = 0, k = 0;
        for (;i < chars.size(); i++) {
            res++;cnt = 1;
            int j = i;
            while(j != chars.size()-1 && chars[j] == chars[j+1]) {
                cnt++;
                j++;
            }
            chars[k++] = chars[i];
            int p = k;
            if (cnt > 1) {
                for (;cnt;cnt/=10) {
                    chars[k++] = cnt%10 + '0';
                    res++;
                }
                reverse(chars.begin()+p,chars.begin()+k);
            }
            i = j;
        }
        return res;
    }
};