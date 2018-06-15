class Solution {
public:
    string reverseStr(string s, int k) {
        int p = 0;
        for (p = 0; p+2*k < s.length();p += 2*k)
            reverse(s.begin()+p,s.begin()+p+k);
        if (p+k < s.length())
            reverse(s.begin()+p, s.begin()+p+k);
        else
            reverse(s.begin()+p,s.end());
        return s;
    }
};