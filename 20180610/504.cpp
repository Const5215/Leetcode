class Solution {
public:
    string convertToBase7(int num) {
        string res = "";
        bool n = 0;
        if (num < 0) {
            n = 1;
            num = -num;
        }
        for(;num;num/=7)
            res = res + (char)('0'+num%7);
        if (res == "") res = "0";
        reverse(res.begin(),res.end());
        if (n)
            res = '-' + res;
        return res;
    }
};