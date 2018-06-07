class Solution {
public:
    string toHex(unsigned int num) {
        string res = "";
        while(num) {
            int ths = 0;
            for (int i = 0; i < 4; i++){
                if (num&1) ths |= (1<<i);
                num >>= 1;
            }
            if (ths < 10) 
                res = (char)(ths+'0') + res;
            else
                res = (char)(ths+'a'-10) + res;
        }
        if (res == "") res = "0";
        return res;
    }
};