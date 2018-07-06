class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> subcnt(s.size());
        subcnt[0] = 1;
        for (int i = 1; i < s.size(); i++)
            subcnt[i] = (s[i] == s[i-1]?subcnt[i-1]+1:1);
        int res = 0;
        for (int i = 0; i < s.size(); i++)
            if (i-subcnt[i] >= 0 && subcnt[i-subcnt[i]] >= subcnt[i])
                res++;
        return res;
    }
};