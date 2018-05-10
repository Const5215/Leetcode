class Solution {
public:
    string convertToTitle(int n) {
        n--;
        string res = "";
        for (;n>=0; n = n/26-1) {
            res = (char)('A'+n%26) + res;
        }
        return res;
    }
};